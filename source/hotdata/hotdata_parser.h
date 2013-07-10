#ifndef _H_XML_PARSER
#define _H_XML_PARSER


#include "hotpot/hp_platform.h"
#include <stdarg.h>
#include <stdio.h>
#include "hotscript/hotlex.h"
#include "hotpot/hp_value.h"
#include "hotprotocol/hp_abstract_writer.h"

#include "datrie/trie.h"
#include "language/language.h"

//�﷨�ڵ��ֵ
typedef struct _SyntacticNode SyntacticNode;
struct _SyntacticNode
{
	HPVar var;
};






typedef struct _DATA_PARSER DATA_PARSER;
struct _DATA_PARSER 
{
	SCANNER_STACK scanner_stack;
	HPAbstractWriter *writer;

	hpint32 result;
	char result_str[MAX_RESULT_STRING_LENGTH];

	const LanguageLib *language_lib;

	

	//���ű�
	Trie *constant;				//��¼�Ѷ���ĳ�������
};

hpint32 data_parser_init(DATA_PARSER *self);

hpint32 data_parser(DATA_PARSER *self, const char* file_name, HPAbstractWriter *writer, const LanguageLib *language_lib);




void dp_on_constant_identifier(DATA_PARSER *self, const YYLTYPE *yylloc, const SyntacticNode* sn_type, const SyntacticNode* sn_identifier);

#endif//_H_XML_PARSER

