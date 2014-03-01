﻿#include <stdio.h>
#include "tlibc/platform/tlibc_platform.h"
#include "tlibc/core/tlibc_error_code.h"

#include "tlibc/protocol/tlibc_xml_reader.h"
#include "tlibc/protocol/tlibc_xml_writer.h"

#include "tlibc/protocol/tlibc_compact_reader.h"
#include "tlibc/protocol/tlibc_compact_writer.h"

#include "tlibc/protocol/tlibc_binary_reader.h"
#include "tlibc/protocol/tlibc_binary_writer.h"

#include "tlibc/protocol/tlibc_xlsx_reader.h"

#include "tlibc/protocol/tlibc_mysql_reader.h"

#include "tlibc/protocol/tlibc_bind_reader.h"
#include "tlibc/protocol/tlibc_bind_writer.h"


#include "protocol_types.h"
#include "protocol_writer.h"
#include "protocol_reader.h"

#include "sql_types.h"
#include "sql_writer.h"
#include "sql_reader.h"

#include <assert.h>
#include "mysql.h"


#include <string.h>

#define MAX_BUFF_SIZE 1024
void test_compact()
{
	char buff[MAX_BUFF_SIZE];
	TLIBC_COMPACT_WRITER compact_writer;
	TLIBC_COMPACT_READER compact_reader;
	message_s message;
	int ret;

	message.mid = E_MID_LOGIN_REQ;
	snprintf(message.body.login_req.name, MAX_NAME_LENGTH, "xiaoxingxing");
	snprintf(message.body.login_req.password, MAX_NAME_LENGTH, "123456");
	message.body.login_req.age = 27;

	tlibc_compact_writer_init(&compact_writer, buff, MAX_BUFF_SIZE);
	ret = tlibc_write_message_s(&compact_writer.super, &message);

	memset(&message, 0, sizeof(message));
	tlibc_compact_reader_init(&compact_reader, buff, MAX_BUFF_SIZE);
	ret = tlibc_read_message_s(&compact_reader.super, &message);
}

void test_binary()
{
	char buff[MAX_BUFF_SIZE];
	TLIBC_BINARY_WRITER writer;
	TLIBC_BINARY_READER reader;
	message_s message;
	int ret;

	message.mid = E_MID_LOGIN_RSP;
	message.body.login_rsp.result = 1;
	//由于result说明登录失败， 所以session_id实际上是无效的， 并不会被读出。
	message.body.login_rsp.session_id = 123321;

	tlibc_binary_writer_init(&writer, buff, MAX_BUFF_SIZE);
	ret = tlibc_write_message_s(&writer.super, &message);

	memset(&message, 0, sizeof(message));
	tlibc_binary_reader_init(&reader, buff, MAX_BUFF_SIZE);
	ret = tlibc_read_message_s(&reader.super, &message);
}

void test_protocol()
{
	//compact型协议具有简单的压缩数据功能， 同时处理速度也非常快， 适合外网数据的传输
	test_compact();

	//binary型协议直接按照C语言默认的编码方式存放， 用小端表示， 速度最快， 不具备压缩功能， 适合内网数据传输
	test_binary();
}



void test_xml()
{
	TLIBC_XML_READER xml_reader;
	TLIBC_XML_WRITER xml_writer;	
	int ret;
	tconnd_config_s config;

	snprintf(config.log_config, MAX_NAME_LENGTH, "/usr/local/tconnd/etc/tconnd_log.xml");
	config.instance_config_num = 2;
	snprintf(config.instance_config[0].ip, IP_LENGTH, "127.0.0.1");
	config.instance_config[0].level = e_low;
	config.instance_config[0].port = 7001;	
	config.instance_config[0].backlog = 5;
	config.instance_config[0].epoll_size = 65536;

	snprintf(config.instance_config[1].ip, IP_LENGTH, "localhost");
	config.instance_config[1].level = e_high;
	config.instance_config[1].port = 7002;
	config.instance_config[1].backlog = 1;
	config.instance_config[1].epoll_size = 1024;

	tlibc_xml_writer_init(&xml_writer, "tconnd.xml");
	ret = tlibc_write_tconnd_config_s(&xml_writer.super, &config);
	tlibc_xml_writer_fini(&xml_writer);
	
	memset(&config, 0, sizeof(tconnd_config_s));

	tlibc_xml_reader_init(&xml_reader);	
	tlibc_xml_reader_push_file(&xml_reader, "tconnd.xml");
	ret = tlibc_read_tconnd_config_s(&xml_reader.super, &config);
	tlibc_xml_reader_pop_file(&xml_reader);

	
	memset(&config, 0, sizeof(tconnd_config_s));
	//用下面这个命令可以来添加查找包含文件的目录
	tlibc_xml_add_include(&xml_reader, "./gen");
	tlibc_xml_reader_push_file(&xml_reader, "./gen/tconnd_inc.xml");
	ret = tlibc_read_tconnd_config_s(&xml_reader.super, &config);
	tlibc_xml_reader_pop_file(&xml_reader);
}

#define MAX_ITEM_NUM 1024
void test_xlsx()
{
	tlibc_xlsx_reader_t xlsx_reader;
	uint32_t i;
	int ret;
	item_table_s item_table[MAX_ITEM_NUM];
	uint32_t item_table_num, row;

	item_table_num = 0;
	memset(&item_table, 0, sizeof(item_table));

	ret = tlibc_xlsx_reader_init(&xlsx_reader, "./gen/item.xlsx");
	//sheet为空表示打开第第一页
	ret = tlibc_xlsx_reader_open_sheet(&xlsx_reader, NULL, 2);
	row = tlibc_xlsx_reader_num_rows(&xlsx_reader);
	for(i = 3; i <= row; ++i)
	{
		tlibc_xlsx_reader_row_seek(&xlsx_reader, i);
		ret = tlibc_read_item_table_s(&xlsx_reader.super, &item_table[item_table_num]);
		if(ret == E_TLIBC_EMPTY)
		{
			continue;
		}
		else if(ret != E_TLIBC_NOERROR)
		{
			assert(0);
		}
		++item_table_num;
	}	
	tlibc_xlsx_reader_close_sheet(&xlsx_reader);
	tlibc_xlsx_reader_fini(&xlsx_reader);
}


void test_mysql()
{
	MYSQL *mysql = NULL;	
	const char *sql = "select * from user_s;";
	int iret;
	MYSQL_RES *res;	
	
	tlibc_mysql_reader_t mysql_reader;
	user_s user;
	TLIBC_ERROR_CODE ret;
	size_t i;
	MYSQL_FIELD *fields;
	size_t fields_num;

	const char* tfields[TLIBC_MYSQL_FIELD_VEC_NUM];	
	size_t tlengths[TLIBC_MYSQL_FIELD_VEC_NUM];
	const char*trow[TLIBC_MYSQL_FIELD_VEC_NUM];
	

	mysql = mysql_init(NULL);
	if(mysql == NULL)
	{		
		printf("mysql_client_init Error %u: %s", mysql_errno(mysql), mysql_error(mysql));
		exit(1);
	}

	if(mysql_real_connect(mysql, "192.168.0.71", "tsqld", "tsqld", "testdb"
		, 3306, NULL, 0) == NULL)
	{
		printf("mysql_real_connect Error %u: %s", mysql_errno(mysql), mysql_error(mysql));
		exit(1);
	}

	iret = mysql_real_query(mysql, sql, strlen(sql));
	if(iret != 0)
	{
		printf("mysql_real_query Error %u: %s", mysql_errno(mysql), mysql_error(mysql));
		exit(1);
	}
	res = mysql_store_result(mysql);
	fields_num = mysql_num_fields(res);
	fields = mysql_fetch_fields(res);
	for(i = 0;i < fields_num; ++i)
	{
		tfields[i] = fields[i].name;
	}

	tlibc_mysql_reader_init(&mysql_reader, tfields, fields_num);
	
	for(;;)
	{
		MYSQL_ROW row = mysql_fetch_row(res);		
		unsigned long *lengths= mysql_fetch_lengths(res);
		if((row == NULL) || (lengths == NULL))
		{
			break;
		}
		for(i = 0;i < fields_num; ++i)
		{
			tlengths[i] = lengths[i];
			trow[i] = row[i];
		}
		tlibc_mysql_reader_fetch(&mysql_reader, trow, tlengths);
		memset(&user, 0 , sizeof(user));
		ret = tlibc_read_user_s(&mysql_reader.super, &user);
	}
	

}

void test_mysql_stmt()
{
	TLIBC_ERROR_CODE ret;
	MYSQL *mysql = NULL;	
	const char *sql_insert = "insert into user_s value(?, ?, ?);";
	MYSQL_STMT *stmt;
	int iret;
	user_s user;
	size_t i;

	MYSQL_BIND   par_bind[1024];

	tlibc_bind_writer_t bind_writer;
	tlibc_bind_const_s bind_vec[1024];
	size_t				bind_vec_num;
//	int ivalue;

	mysql = mysql_init(NULL);
	if(mysql == NULL)
	{		
		printf("mysql_client_init Error %u: %s", mysql_errno(mysql), mysql_error(mysql));
		exit(1);
	}

	if(mysql_real_connect(mysql, "192.168.0.71", "tsqld", "tsqld", "testdb"
		, 3306, NULL, 0) == NULL)
	{
		printf("mysql_real_connect Error %u: %s", mysql_errno(mysql), mysql_error(mysql));
		exit(1);
	}

	stmt = mysql_stmt_init(mysql);
	if(stmt == NULL)
	{
		printf("mysql_stmt_init Error %u: %s", mysql_stmt_error(stmt), mysql_stmt_error(stmt));
		exit(1);
	}

	if(mysql_stmt_prepare(stmt, sql_insert, strlen(sql_insert)))
	{
		printf("mysql_stmt_prepare Error %u: %s", mysql_stmt_error(stmt), mysql_stmt_error(stmt));
		exit(1);
	}

	user.type = e_admin;
	user.id = 1;
	snprintf(user.username, MAX_NAME_LENGTH, "xiaoxingxing");
	tlibc_bind_writer_init(&bind_writer, bind_vec, sizeof(bind_vec));
	ret = tlibc_write_user_s(&bind_writer.super, &user);
	memset(par_bind, 0, sizeof(par_bind));
	bind_vec_num = bind_writer.idx;
	for(i = 0;i < bind_vec_num; ++i)
	{
		par_bind[i].buffer = (void*)bind_vec[i].buff;
		switch(bind_vec[i].type)
		{
		case e_tlibc_bind_uint8:
		case e_tlibc_bind_int8:
			par_bind[i].buffer_type = MYSQL_TYPE_TINY;
			break;
		case e_tlibc_bind_uint16:
		case e_tlibc_bind_int16:
			par_bind[i].buffer_type = MYSQL_TYPE_SHORT;
			break;
		case e_tlibc_bind_uint32:
		case e_tlibc_bind_int32:
			par_bind[i].buffer_type = MYSQL_TYPE_LONG;
			break;
		case e_tlibc_bind_uint64:
		case e_tlibc_bind_int64:
			par_bind[i].buffer_type = MYSQL_TYPE_LONGLONG;
			break;
		case e_tlibc_bind_double:
			par_bind[i].buffer_type = MYSQL_TYPE_DOUBLE;
			break;
		case e_tlibc_bind_char:
			par_bind[i].buffer_type = MYSQL_TYPE_STRING;
			par_bind[i].buffer_length = 1;
			break;
		case e_tlibc_bind_string:
			par_bind[i].buffer_type = MYSQL_TYPE_STRING;
			par_bind[i].buffer_length = bind_vec[i].buff_size;
			break;
		default:
			assert(0);
		}
		par_bind[i].is_null = NULL;
		par_bind[i].length = NULL;
	}
	/*
	par_bind[0].buffer_type= MYSQL_TYPE_LONG;
	par_bind[0].buffer= (char *)&ivalue;
	par_bind[0].is_null= 0;
	par_bind[0].length= 0;
	*/
	iret = mysql_stmt_bind_param(stmt, par_bind);
	if(iret)
	{
		printf("mysql_stmt_bind_param Error %u: %s", mysql_stmt_error(stmt), mysql_stmt_error(stmt));
		exit(1);
	}
	//ivalue = 10;
	iret = mysql_stmt_execute(stmt);
	if(iret != 0)
	{
		printf("mysql_real_query Error %u: %s", mysql_stmt_error(stmt), mysql_stmt_error(stmt));
		exit(1);
	}

}

int main()
{
	test_protocol();
	
	test_xml();
	
	test_xlsx();

	//test_mysql();

	test_mysql_stmt();
	
	return 0;
}
