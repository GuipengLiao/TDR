#ifndef _H_CHECK
#define _H_CHECK


#include "platform/tlibc_platform.h"

#include "parse/parser.h"



//�����Ŷ���
void check_identifier_defined(const SYMBOLS *symbols, const YYLTYPE *yylloc, const tchar *prefix, const tchar *identifier);

//������δ����
void check_identifier_not_defined(const SYMBOLS *symbols, const YYLTYPE *yylloc, const tchar *prefix, const tchar *identifier);

//�������Ƿ�ָ��һ������enum, struct, union
void check_identifier_is_type(const SYMBOLS *symbols, const YYLTYPE *yylloc, const tchar *prefix, const tchar *identifier);

//������ָ��һ��ֵvalue, enumdef
void check_identifier_is_value(const SYMBOLS *symbols, const YYLTYPE *yylloc, const tchar *prefix, const tchar *identifier);

//�����Ų�ָ��һ��ֵvalue, enumdef
void check_identifier_not_defined_as_value(const SYMBOLS *symbols, const YYLTYPE *yylloc, const tchar *prefix, const tchar *identifier);

//�������Ƿ�ָ��һ������������
void check_identifier_is_positive_integer(const SYMBOLS *symbols, const YYLTYPE *yylloc, const tchar *prefix, const tchar *identifier);

//���string���ȶ���
void check_string_length_defined(const YYLTYPE *yylloc, const ST_SIMPLE_TYPE *symbol_type);

//�������������
void check_integer_type(const SYMBOLS *symbols, const YYLTYPE *yylloc, const ST_SIMPLE_TYPE *simple_type);

//���ֵ������
void check_integer_value(const SYMBOLS *symbols, const YYLTYPE *yylloc, const ST_VALUE *value);

//������ָ��һ���������͵�struct��Ա
void check_identifier_refer_to_a_field_with_integer_type(const SYMBOLS *symbols, const YYLTYPE *yylloc, const tchar *prefix, const tchar *identifier);

//���ʵ�ʲ�������ʽ�����Ƿ�ƥ��
void check_arguments(const SYMBOLS *symbols, const YYLTYPE *yylloc, const ST_TYPE *type, const ST_ARGUMENTS *arguments);

//����ַ��������Ƿ񳬹�����
void check_strlen_too_long(const YYLTYPE *yylloc, const tchar *str, const tchar *suffix, tuint32 limit);

//������ͺ�ֵ�Ƿ�ƥ��
void check_value_type(const SYMBOLS *symbols, const YYLTYPE *yylloc, const ST_SIMPLE_TYPE *type, const ST_VALUE *val);

//��鲻�����ظ�ֵ��ö������
void check_simpletype_is_enum(const SYMBOLS *symbols, const YYLTYPE *yylloc, const ST_SIMPLE_TYPE *simple_type);

//���ö�ٲ������ظ�Ԫ��
void check_enumdef_is_unique(const YYLTYPE *yylloc, const ST_ENUM *pn_enum, tuint32 index);

//����ַ����Ƿ����
void check_str_equal(const YYLTYPE *yylloc, const tchar *src, const tchar* dst);

#endif //_H_CHECK
