#ifndef _H_XERROR
#define _H_XERROR

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//								���ļ���һ������"XERROR"��XЭ���C����ͷ�ļ�
//								����ر�֤ͷ�ļ�����XЭ���Ҫ�� �Ƽ�ʹ��XC�������XЭ���ļ�
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma pack(push,1)

#include "typedef.h"



typedef enum tagXE_XBASE
{
	XNOERROR                                                           = -10000,
	XERROR                                                             = -10001,
	XBAD_PARAMETER                                                     = -10002,
	XBYTEBUFF_CAN_NOT_DECODE_THE_TYPE                                  = -10003,
	XNOT_ENOUGH_BYTEBUFF_SIZE                                          = -10004,
}XE_XBASE;


typedef enum tagXE_OS
{
	XWOULDBLOCK                                                        = -20000,
	XINPROCESS                                                         = -20001,
}XE_OS;


typedef enum tagXE_XSN
{
	XSTACK_EMPTY                                                       = -30000,
	XSTACK_OVERFOLLOW                                                  = -30001,
}XE_XSN;



#pragma pack(pop)

#endif //_H_XERROR

