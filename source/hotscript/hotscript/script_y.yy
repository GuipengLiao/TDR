%{
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
}//code requires end

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
	{
	}

StatementList :
	StatementList Statement
	{
	}
|
	{
	}
	
Statement:
	tok_literal 
	{
		hotscript_do_literal(ss, &$1);
	}
|	Prefix tok_identifier ArrayIndex
	{
		hotscript_do_push(ss, &$1, &$2);
		hotscript_do_push_index(ss, &$3);
		
		hotscript_do_echo_trie(ss);
		
		hotscript_do_pop_index(ss, &$3);
		hotscript_do_pop(ss, &$2);
	}
|	Prefix tok_identifier ArrayIndex
	'{'
	{
		hotscript_do_push(ss, &$1, &$2);
		hotscript_do_push_index(ss, &$3);
	}
	StatementList
	'}'
	{
		hotscript_do_pop_index(ss, &$3);
		hotscript_do_pop(ss, &$2);
	}
|	tok_text 
	{
		hotscript_do_text(ss, &$1);
	}


ArrayIndex :
	'[' tok_integer ']'
	{
		$$.var.type = E_HP_INT32;
		$$.var.val.i32 = $2.var.val.i32;	//ָ���±�
	}
|	'[' '*' ']'
	{
		$$.var.type = E_HP_INT32;
		$$.var.val.i32 = -1;		//������չ��Ԫ�أ� ֱ��������
	}
|
	{
		$$.var.type = E_HP_INT32;
		$$.var.val.i32 = -2;		//Ĭ��Ϊ��һ��Ԫ��
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
