#ifndef _H_HP_ERROR_CODE
#define _H_HP_ERROR_CODE

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//								���ļ���һ������"hp_error_code.dd"��XЭ���C����ͷ�ļ�
//								����ر�֤ͷ�ļ�����XЭ���Ҫ�� �Ƽ�ʹ��XC�������XЭ���ļ�
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma pack(push,1)

#include "hotpot/hp_platform.h"


#define HP_COMMON_ERROR_CODE_SECTION_UPPER_BOUND                       (0)
#define HP_COMMON_ERROR_CODE_SECTION_LOWER_BOUND                       (-10000)

typedef enum tagCOMMON_ERROR_CODE
{
	E_HP_NOERROR                                                       = 0,
	E_HP_ERROR                                                         = -1,
	E_HP_BAD_PARAMETER                                                 = -2,
	E_HP_NOT_ENOUGH_BYTEBUFF_SIZE                                      = -3,
}COMMON_ERROR_CODE;



#pragma pack(pop)

#endif //_H_HP_ERROR_CODE

