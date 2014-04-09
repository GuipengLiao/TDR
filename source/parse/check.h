#ifndef _H_CHECK
#define _H_CHECK


#include "platform/tlibc_platform.h"

#include "parse/parser.h"
#include <stdint.h>


//�����Ŷ���
void check_identifier_defined(const symbols_t *symbols, const YYLTYPE *yylloc, const char *prefix, const char *identifier);

//������δ����
void check_identifier_not_defined(const symbols_t *symbols, const YYLTYPE *yylloc, const char *prefix, const char *identifier);

//�������Ƿ�ָ��һ������enum, struct, union
void check_identifier_is_type(const symbols_t *symbols, const YYLTYPE *yylloc, const char *prefix, const char *identifier);

//������ָ��һ��ֵvalue, enumdef
void check_identifier_is_value(const symbols_t *symbols, const YYLTYPE *yylloc, const char *prefix, const char *identifier);

//�����Ų�ָ��һ��ֵvalue, enumdef
void check_identifier_not_defined_as_value(const symbols_t *symbols, const YYLTYPE *yylloc, const char *prefix, const char *identifier);

//�������Ƿ�ָ��һ������������
void check_identifier_is_positive_integer(const symbols_t *symbols, const YYLTYPE *yylloc, const char *prefix, const char *identifier);

//���string���ȶ���
void check_string_length_defined(const YYLTYPE *yylloc, const ST_SIMPLE_TYPE *symbol_type);

//���string����δ����
void check_string_length(const YYLTYPE *yylloc, const ST_SIMPLE_TYPE *symbol_type, int defined);

//�������������
void check_integer_type(const symbols_t *symbols, const YYLTYPE *yylloc, const ST_SIMPLE_TYPE *simple_type);

//���ֵ������
void check_integer_value(const symbols_t *symbols, const YYLTYPE *yylloc, const ST_VALUE *value);

//������ָ��һ���������͵�struct��Ա
void check_identifier_refer_to_a_field_with_integer_type(const symbols_t *symbols, const YYLTYPE *yylloc, const char *prefix, const char *identifier);

//���ʵ�ʲ�������ʽ�����Ƿ�ƥ��
void check_arguments(const symbols_t *symbols, const YYLTYPE *yylloc, const ST_TYPE *type, const ST_ARGUMENTS *arguments);

//����ַ��������Ƿ񳬹�����
void check_strlen_too_long(const YYLTYPE *yylloc, const char *str, const char *suffix, uint32_t limit);

//������ͺ�ֵ�Ƿ�ƥ��
void check_value_type(const symbols_t *symbols, const YYLTYPE *yylloc, const ST_SIMPLE_TYPE *type, const ST_VALUE *val);

//��鲻�����ظ�ֵ��ö������
void check_simpletype_is_enum(const symbols_t *symbols, const YYLTYPE *yylloc, const ST_SIMPLE_TYPE *simple_type);

//���ö�ٲ������ظ�Ԫ��
void check_enumdef_is_unique(const YYLTYPE *yylloc, const ST_ENUM *pn_enum, uint32_t index);

//����ַ����Ƿ����
void check_str_equal(const YYLTYPE *yylloc, const char *src, const char* dst);

#endif //_H_CHECK
