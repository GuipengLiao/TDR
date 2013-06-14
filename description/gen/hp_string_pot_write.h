#ifndef _H_HP_STRING_POT_WRITE
#define _H_HP_STRING_POT_WRITE

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//								���ļ���һ������"hp_string_pot.dd"��Э���ļ�����Ӧ��C���Խ����ļ�
//								����ر�֤���ļ�����XЭ���Ҫ�� �Ƽ�ʹ��XC�������XЭ���ļ�
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include "hotpot/hp_platform.h"

#ifndef _DEF_DDEKIT_ENCODING_WRITER
#define _DEF_DDEKIT_ENCODING_WRITER
typedef struct tagDDEKIT_ENCODING_WRITER DDEKIT_ENCODING_WRITER;
#endif//_DEF_DDEKIT_ENCODING_WRITER
#ifndef _DEF_HP_STRING
#define _DEF_HP_STRING
typedef struct tagHP_STRING HP_STRING;
#endif//_DEF_HP_STRING
void HP_STRING_write(const HP_STRING* data, DDEKIT_ENCODING_WRITER *dp);

#ifndef _DEF_HP_STRING_POT
#define _DEF_HP_STRING_POT
typedef struct tagHP_STRING_POT HP_STRING_POT;
#endif//_DEF_HP_STRING_POT
void HP_STRING_POT_write(const HP_STRING_POT* data, DDEKIT_ENCODING_WRITER *dp);

#endif //_H_HP_STRING_POT_WRITE

