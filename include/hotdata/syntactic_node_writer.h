/**
 * Autogenerated by HotData (0.0.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#ifndef _H_hotdata_syntactic_node_hd_WRITER_HEADER
#define _H_hotdata_syntactic_node_hd_WRITER_HEADER
#include "hotpot/hp_platform.h"
#include "hotlib/hp_error_code.h"
#include "hotprotocol/hp_abstract_writer.h"
#include "hotdata/syntactic_node.h"
#include "hotlib/hp_config_writer.h"
HP_ERROR_CODE write_ST_UNIX_COMMENT(HPAbstractWriter *self, const ST_UNIX_COMMENT *data);
HP_ERROR_CODE write_SN_VALUE_TYPE_name(HPAbstractWriter *self, SN_VALUE_TYPE data);
HP_ERROR_CODE write_SN_VALUE_TYPE_number(HPAbstractWriter *self, SN_VALUE_TYPE data);
HP_ERROR_CODE write_SN_VALUE_TYPE(HPAbstractWriter *self, SN_VALUE_TYPE data);
HP_ERROR_CODE write_UN_VALUE(HPAbstractWriter *self, const UN_VALUE *data , SN_VALUE_TYPE s);
HP_ERROR_CODE write_ST_VALUE(HPAbstractWriter *self, const ST_VALUE *data);
HP_ERROR_CODE write_SN_SIMPLE_TYPE_name(HPAbstractWriter *self, SN_SIMPLE_TYPE data);
HP_ERROR_CODE write_SN_SIMPLE_TYPE_number(HPAbstractWriter *self, SN_SIMPLE_TYPE data);
HP_ERROR_CODE write_SN_SIMPLE_TYPE(HPAbstractWriter *self, SN_SIMPLE_TYPE data);
HP_ERROR_CODE write_SN_CONTAINER_TYPE_name(HPAbstractWriter *self, SN_CONTAINER_TYPE data);
HP_ERROR_CODE write_SN_CONTAINER_TYPE_number(HPAbstractWriter *self, SN_CONTAINER_TYPE data);
HP_ERROR_CODE write_SN_CONTAINER_TYPE(HPAbstractWriter *self, SN_CONTAINER_TYPE data);
HP_ERROR_CODE write_SN_TYPE_name(HPAbstractWriter *self, SN_TYPE data);
HP_ERROR_CODE write_SN_TYPE_number(HPAbstractWriter *self, SN_TYPE data);
HP_ERROR_CODE write_SN_TYPE(HPAbstractWriter *self, SN_TYPE data);
HP_ERROR_CODE write_ST_TYPE(HPAbstractWriter *self, const ST_TYPE *data);
HP_ERROR_CODE write_ST_Parameter(HPAbstractWriter *self, const ST_Parameter *data);
HP_ERROR_CODE write_ST_Parameters(HPAbstractWriter *self, const ST_Parameters *data);
HP_ERROR_CODE write_ST_ARGUMENTS(HPAbstractWriter *self, const ST_ARGUMENTS *data);
HP_ERROR_CODE write_ST_EXPRESSION_OPER_name(HPAbstractWriter *self, ST_EXPRESSION_OPER data);
HP_ERROR_CODE write_ST_EXPRESSION_OPER_number(HPAbstractWriter *self, ST_EXPRESSION_OPER data);
HP_ERROR_CODE write_ST_EXPRESSION_OPER(HPAbstractWriter *self, ST_EXPRESSION_OPER data);
HP_ERROR_CODE write_ST_Expression(HPAbstractWriter *self, const ST_Expression *data);
HP_ERROR_CODE write_ST_CONDITION(HPAbstractWriter *self, const ST_CONDITION *data);
HP_ERROR_CODE write_ST_FIELD(HPAbstractWriter *self, const ST_FIELD *data);
HP_ERROR_CODE write_TA_TYPE_name(HPAbstractWriter *self, TA_TYPE data);
HP_ERROR_CODE write_TA_TYPE_number(HPAbstractWriter *self, TA_TYPE data);
HP_ERROR_CODE write_TA_TYPE(HPAbstractWriter *self, TA_TYPE data);
HP_ERROR_CODE write_ST_TypeAnnotation(HPAbstractWriter *self, const ST_TypeAnnotation *data);
HP_ERROR_CODE write_ST_TypeAnnotations(HPAbstractWriter *self, const ST_TypeAnnotations *data);
HP_ERROR_CODE write_ST_Import(HPAbstractWriter *self, const ST_Import *data);
HP_ERROR_CODE write_ST_Const(HPAbstractWriter *self, const ST_Const *data);
HP_ERROR_CODE write_ST_ENUM_DEF(HPAbstractWriter *self, const ST_ENUM_DEF *data);
HP_ERROR_CODE write_ST_ENUM(HPAbstractWriter *self, const ST_ENUM *data);
HP_ERROR_CODE write_ST_FIELD_LIST(HPAbstractWriter *self, const ST_FIELD_LIST *data);
HP_ERROR_CODE write_ST_STRUCT(HPAbstractWriter *self, const ST_STRUCT *data);
HP_ERROR_CODE write_ST_UNION(HPAbstractWriter *self, const ST_UNION *data);
HP_ERROR_CODE write_ST_TYPEDEF(HPAbstractWriter *self, const ST_TYPEDEF *data);
HP_ERROR_CODE write_EN_DEFINITION_TYPE_name(HPAbstractWriter *self, EN_DEFINITION_TYPE data);
HP_ERROR_CODE write_EN_DEFINITION_TYPE_number(HPAbstractWriter *self, EN_DEFINITION_TYPE data);
HP_ERROR_CODE write_EN_DEFINITION_TYPE(HPAbstractWriter *self, EN_DEFINITION_TYPE data);
HP_ERROR_CODE write_UN_DEFINITION(HPAbstractWriter *self, const UN_DEFINITION *data , EN_DEFINITION_TYPE s);
HP_ERROR_CODE write_ST_DEFINITION(HPAbstractWriter *self, const ST_DEFINITION *data);
#endif//_H_hotdata_syntactic_node_hd_WRITER_HEADER
