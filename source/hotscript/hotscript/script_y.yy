%{
//����Ҫ����������⣬ ��Ȼbison���ɵ��ļ����벻��
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "hotpot/hp_platform.h"
#include "hotpot/hp_error.h"




#define YYERROR_VERBOSE

%}
%locations

%code requires
{
#include "hotscript/script_parser.h"
#include "hotscript/hot_vm.h"

#define YYSTYPE SP_NODE
#define YYMALLOC
#define YYFREE
#define YYLEX_PARAM ss
}

%define api.pure
%parse-param { SCANNER_STACK *ss }
%pure_parser

%token tok_import
%token tok_literal
%token tok_integer
%token tok_identifier
%token tok_text

%start Script

%%

Script :
	StatementList

StatementList :
	StatementList Statement
	{
	}
|
	{
	}
	
Statement:
	tok_text 
	{
		hotscript_do_text(ss, &$1);
	}
|
	tok_literal 
	{
		hotscript_do_literal(ss, &$1);
	}
|	Prefix tok_identifier ArrayIndex
	{
		hotscript_do_field_begin(ss, &$$, &$1, &$2);
		hotscript_do_vector_begin(ss, &$$, &$3);
		hotscript_do_vector_seek(ss, &$$, &$3);

		hotscript_do_echo_field(ss, &$$);

		hotscript_do_jmp(ss, &$$);//���echoʧ���ˣ� ��ô����jmp����һ��		
		hotscript_do_vector_end(ss, &$$, &$3);//���vector beginʧ���ˣ� ��ô������һ��
		hotscript_do_field_end(ss, &$$, &$2);//���field beginʧ���ˣ� ��ô������һ��
	}
|	Prefix tok_identifier ArrayIndex
	'{'
	{
		hotscript_do_field_begin(ss, &$$, &$1, &$2);
		hotscript_do_vector_begin(ss, &$$, &$3);
		hotscript_do_vector_seek(ss, &$$, &$3);
	}
	StatementList
	'}'
	{
		hotscript_do_jmp(ss, &$$);
		hotscript_do_vector_end(ss, &$$, &$3);
		hotscript_do_field_end(ss, &$$, &$2);
	}


ArrayIndex :
	'[' tok_integer ']'
	{
		$$.it = E_INDEX_GIVEN;
		$$.var.type = E_HP_UINT32;
		$$.var.val.ui32 = (hpuint32)$2.var.val.i64;	//ָ���±꣬ ����int32��ô�죿
	}
|	'[' '*' ']'
	{
		$$.it = E_INDEX_ALL;						//������չ��Ԫ�أ� ֱ��������
	}
|
	{
		$$.it = E_INDEX_NULL;						//Ĭ��Ϊ��һ��Ԫ��
	}

Prefix:
	'@'
	{
		$$.var.type = E_HP_CHAR;
		$$.var.val.c = '@';//�ֲ�����
	}
|	'#'
	{
		$$.var.type = E_HP_CHAR;
		$$.var.val.c = '#';//ȫ�ֱ���
	}
|	'$'
	{
		$$.var.type = E_HP_CHAR;
		$$.var.val.c = '$';//�������ж�ջ
	}


%%
