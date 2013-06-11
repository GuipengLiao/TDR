#ifndef _H_HP_ERROR
#define _H_HP_ERROR

//hotpot�����������
typedef enum tagHP_HOTPOT_ERROR_CODE_SECTION
{
	E_HP_COMMON_SECTION														= 0,
	E_HP_NUMBER_SECTION														= 10000,
}HP_HOTPOT_ERROR_CODE_SECTION;


//���ô���������
typedef enum tagHP_HOTPOT_ERROR_CODE_COMMON
{
	E_HP_NOERROR                                                           = E_HP_COMMON_SECTION,
	E_HP_ERROR                                                             = E_HP_COMMON_SECTION - 1,
	E_HP_BAD_PARAMETER                                                     = E_HP_COMMON_SECTION - 2,
}HP_HOTPOT_ERROR_CODE_COMMON;


//number��������
typedef enum tagHP_HOTPOT_ERROR_CODE_NUMBER
{
	E_HP_NOT_ENOUGH_BYTEBUFF_SIZE                                          = E_HP_NUMBER_SECTION,
}HP_HOTPOT_ERROR_CODE_NUMBER;


#endif //_H_HP_ERROR

