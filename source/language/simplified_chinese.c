#include "language/language.h"

const char* tdata_strerror(EN_TD_LANGUAGE_STRING sid)
{
	switch(sid)
	{
	case E_LS_UNKNOW:
		return "δ֪����.";
	case E_LS_IDENTIFIER_NOT_DEFINED:
		return "����δ����[%s::%s]";
	case E_LS_IDENTIFIER_REDEFINITION:
		return "[%s::%s]�����ض���";
	case E_LS_IDENTIFIER_NOT_INTEGER:
		return "����[%s::%s]���ǺϷ�����";
	case E_LS_IDENTIFIER_NOT_STRING:
		return "��ʶ��[%s]����[%s]";
	case E_LS_STRING_LENGTH_NOT_DEFINED:
		return "string����δ����";
	case E_LS_IDENTIFIER_LENGTH_ERROR:
		return "���ų��ȳ���%u";
	case E_LS_NOT_INTEGER_TYPE:
		return "������������";
	case E_LS_NOT_INTEGER_VALUE:
		return "���ǺϷ�����";
	case E_LS_ARGUMENT_TYPE_MISMATCH:
		return "�������Ͳ�ƥ��";
	case E_LS_CANNOT_USE_RESERVED_LANGUAGE_KEYWORD:
		return "����ʹ�ñ�����[%s]";
	case E_LS_SYNTAX_ERROR:
		return "�﷨����ʱ��������[%s]";
	case E_LS_CANNOT_OPEN_FILE:
		return "�޷����ļ�[%s]";
	case E_LS_OUT_OF_MEMORY:
		return "��ͼ���ļ�[%s]�����ڴ�������";
	case E_LS_CHARACTER_CONSTANT_FORMAT_ERROR:
		return "�ַ��ͳ�����ʽ����";
	case E_LS_STRING_CONSTANT_FORMAT_ERROR:
		return "�ַ����ͳ�����ʽ����";
	case E_LS_NUMBER_ERROR_RANGE:
		return "���ֳ���������Χ";
	case E_LS_CAN_NOT_DEFINE_STRING_LENGTH_HERE:
		return "���峣��ʱ����ָ��string���͵ĳ���";
	case E_LS_CONSTANT_TYPES_DO_NOT_MATCH:
		return "�������Ͳ�ƥ��";
	case E_LS_CONST_TYPE_ERROR:
		return "�������ʹ���";
	case E_LS_ENUM_HAVE_EQUAL_ELEMENTS:
		return "ö�����ͺ����ظ�Ԫ��[%s]��[%s]";
	case E_LS_TOO_MANY_MEMBERS:
		return "���ͳ�Ա���������Գ���[%u]";
	case E_LS_TOO_MANY_PARAMETERS:
		return "��ʽ���������Գ���[%u]��";
	case E_LS_TOO_MANY_ARGUMENTS:
		return "ʵ�ʲ��������Գ���[%u]��";
	case E_LS_NOT_ENUM_TYPE:
		return "����ö������";
	default:
		return "δ֪����";
	}
}
