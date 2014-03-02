#include <stdio.h>
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
	//����result˵����¼ʧ�ܣ� ����session_idʵ��������Ч�ģ� �����ᱻ������
	message.body.login_rsp.session_id = 123321;

	tlibc_binary_writer_init(&writer, buff, MAX_BUFF_SIZE);
	ret = tlibc_write_message_s(&writer.super, &message);

	memset(&message, 0, sizeof(message));
	tlibc_binary_reader_init(&reader, buff, MAX_BUFF_SIZE);
	ret = tlibc_read_message_s(&reader.super, &message);
}

void test_protocol()
{
	//compact��Э����м򵥵�ѹ�����ݹ��ܣ� ͬʱ�����ٶ�Ҳ�ǳ��죬 �ʺ��������ݵĴ���
	test_compact();

	//binary��Э��ֱ�Ӱ���C����Ĭ�ϵı��뷽ʽ��ţ� ��С�˱�ʾ�� �ٶ���죬 ���߱�ѹ�����ܣ� �ʺ��������ݴ���
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
	//��������������������Ӳ��Ұ����ļ���Ŀ¼
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
	//sheetΪ�ձ�ʾ�򿪵ڵ�һҳ
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

	MYSQL_BIND   par_bind[1024];

	tlibc_bind_writer_t bind_writer;

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

	memset(&par_bind, 0, sizeof(par_bind));
	tlibc_bind_writer_init(&bind_writer, par_bind, sizeof(par_bind));
	

	user.exp = 123.321;
	user.gold = UINT64_MAX;
	user.id = 1;
	snprintf(user.username, MAX_NAME_LENGTH, "xiaoxingxing");

	ret = tlibc_write_user_s(&bind_writer.super, &user);
	iret = mysql_stmt_bind_param(stmt, par_bind);
	if(iret)
	{
		printf("mysql_stmt_bind_param Error %u: %s", mysql_stmt_error(stmt), mysql_stmt_error(stmt));
		exit(1);
	}
	
	


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
