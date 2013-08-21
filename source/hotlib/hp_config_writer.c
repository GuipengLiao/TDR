/**
 * Autogenerated by HotData (0.0.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "hotpot/hp_platform.h"
#include "hotlib/hp_config.h"
#include "hotlib/hp_config_writer.h"
HP_ERROR_CODE write_hpbool_name(HPAbstractWriter *self, const hpbool data)
{
    switch(data)
    {
        case hptrue:
            if(write_enum_name(self, "hptrue") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case hpfalse:
            if(write_enum_name(self, "hpfalse") != E_HP_NOERROR) goto ERROR_RET;
            break;
    }
    return E_HP_NOERROR;
ERROR_RET:
    return E_HP_ERROR;
}
HP_ERROR_CODE write_hpbool_number(HPAbstractWriter *self, const hpbool data)
{
    return write_enum_number(self, data);
}
HP_ERROR_CODE write_hpbool(HPAbstractWriter *self, const hpbool data)
{
    if(write_hpbool_name(self, data) != E_HP_NOERROR) goto ERROR_RET;
    if(write_hpbool_number(self, data) != E_HP_NOERROR) goto ERROR_RET;
    return E_HP_NOERROR;
ERROR_RET:
    return E_HP_ERROR;
}
HP_ERROR_CODE write_HPType_name(HPAbstractWriter *self, const HPType data)
{
    switch(data)
    {
        case E_HP_INT8:
            if(write_enum_name(self, "E_HP_INT8") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_INT16:
            if(write_enum_name(self, "E_HP_INT16") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_INT32:
            if(write_enum_name(self, "E_HP_INT32") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_INT64:
            if(write_enum_name(self, "E_HP_INT64") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_UINT8:
            if(write_enum_name(self, "E_HP_UINT8") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_UINT16:
            if(write_enum_name(self, "E_HP_UINT16") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_UINT32:
            if(write_enum_name(self, "E_HP_UINT32") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_UINT64:
            if(write_enum_name(self, "E_HP_UINT64") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_CHAR:
            if(write_enum_name(self, "E_HP_CHAR") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_BYTES:
            if(write_enum_name(self, "E_HP_BYTES") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_STRING:
            if(write_enum_name(self, "E_HP_STRING") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_DOUBLE:
            if(write_enum_name(self, "E_HP_DOUBLE") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_BOOL:
            if(write_enum_name(self, "E_HP_BOOL") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_NULL:
            if(write_enum_name(self, "E_HP_NULL") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_VECTOR:
            if(write_enum_name(self, "E_HP_VECTOR") != E_HP_NOERROR) goto ERROR_RET;
            break;
        case E_HP_OBJECT:
            if(write_enum_name(self, "E_HP_OBJECT") != E_HP_NOERROR) goto ERROR_RET;
            break;
    }
    return E_HP_NOERROR;
ERROR_RET:
    return E_HP_ERROR;
}
HP_ERROR_CODE write_HPType_number(HPAbstractWriter *self, const HPType data)
{
    return write_enum_number(self, data);
}
HP_ERROR_CODE write_HPType(HPAbstractWriter *self, const HPType data)
{
    if(write_HPType_name(self, data) != E_HP_NOERROR) goto ERROR_RET;
    if(write_HPType_number(self, data) != E_HP_NOERROR) goto ERROR_RET;
    return E_HP_NOERROR;
ERROR_RET:
    return E_HP_ERROR;
}
