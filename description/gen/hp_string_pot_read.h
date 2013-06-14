#ifndef _H_HP_STRING_POT_READ
#define _H_HP_STRING_POT_READ

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//								���ļ���һ������"hp_string_pot.dd"��Э���ļ�����Ӧ��C���Խ����ļ�
//								����ر�֤���ļ�����XЭ���Ҫ�� �Ƽ�ʹ��XC�������XЭ���ļ�
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include "hotpot/hp_platform.h"

#ifndef _DEF_DDEKIT_ENCODING_READER
#define _DEF_DDEKIT_ENCODING_READER
typedef struct tagDDEKIT_ENCODING_READER DDEKIT_ENCODING_READER;
#endif//_DEF_DDEKIT_ENCODING_READER
#ifndef _DEF_HP_STRING
#define _DEF_HP_STRING
typedef struct tagHP_STRING HP_STRING;
#endif//_DEF_HP_STRING
void HP_STRING_read(HP_STRING* data, DDEKIT_ENCODING_READER *dp);

#ifndef _DEF_HP_STRING_POT
#define _DEF_HP_STRING_POT
typedef struct tagHP_STRING_POT HP_STRING_POT;
#endif//_DEF_HP_STRING_POT
void HP_STRING_POT_read(HP_STRING_POT* data, DDEKIT_ENCODING_READER *dp);

#endif //_H_HP_STRING_POT_READ

