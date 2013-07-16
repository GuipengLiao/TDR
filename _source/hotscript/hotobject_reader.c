#include "hotscript/hotobject_reader.h"

#include "hotpot/hp_platform.h"

#include "hotpot/hp_error.h"




static const HotObject *hotobject_get(HotObjectReader *self)
{
	return self->stack[self->stack_num - 1].ho;
}

static hpint32 hotobject_push(HotObjectReader *self, const HotObject *ho)
{
	self->stack[self->stack_num].ho = ho;
	++(self->stack_num);

	return E_HP_NOERROR;
}

hpint32 hotobject_read_struct_begin(HPAbstractReader *super, const char *struct_name)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	return E_HP_NOERROR;
}

hpint32 hotobject_read_struct_end(HPAbstractReader *super, const char *struct_name)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	return E_HP_NOERROR;
}

hpint32 hotobject_read_field_begin(HPAbstractReader *super, const char *var_name, hpuint32 len)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	const HotObject *new_ob;
	hpint32 ret;
	char name[1024];
	hpuint32 i;
	for(i = 0; i < len; ++i)
	{
		name[i] = var_name[i];
	}
	name[i] = 0;
	for(i = self->stack_num; i > 0; --i)
	{
		ret = trie_retrieve(self->stack[i - 1].ho->keys, name, &new_ob);
		if(ret)
		{
			hotobject_push(self, new_ob);
			return E_HP_NOERROR;
		}
	}
	
ERROR_RET:
	return E_HP_ERROR;
}

hpint32 hotobject_read_vector_item_begin(HPAbstractReader *super, hpuint32 index)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	const HotObject *ob = hotobject_get(self);	
	hpint32 count;	
	const HotObject *new_ob;
	hpint32 ret;
	char name[1024];	
	hpuint32 len = 0;

	count = index;
	len = 0;	
	do
	{
		name[len++] = '0' + count % 10;
		count/=10;
	}while(count > 0);
	name[len] = 0;

	ret = trie_retrieve(ob->keys, name, &new_ob);
	if(!ret)
	{
		goto ERROR_RET;
	}
	hotobject_push(self, new_ob);

	return E_HP_NOERROR;
ERROR_RET:
	return E_HP_ERROR;
}

hpint32 hotobject_read_field_end(HPAbstractReader *super, const char *var_name, hpuint32 len)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	--(self->stack_num);
	return E_HP_NOERROR;
}


hpint32 hotobject_read_vector_begin(HPAbstractReader *super)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);

	return E_HP_NOERROR;
}

hpint32 hotobject_read_vector_end(HPAbstractReader *super)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);

	return E_HP_NOERROR;
}

static hpint32 hotobject_read_hpint8(HPAbstractReader *super, hpint8 *val)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	const HotObject *ob = hotobject_get(self);
	*val = ob->var.val.i8;

	return E_HP_NOERROR;
}

static hpint32 hotobject_read_double(HPAbstractReader *super, hpdouble *val)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	const HotObject *ob = hotobject_get(self);
	*val = ob->var.val.d;

	return E_HP_NOERROR;
}

static hpint32 hotobject_read_hpint64(HPAbstractReader *super, hpint64 *val)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	const HotObject *ob = hotobject_get(self);
	*val = ob->var.val.i64;

	return E_HP_NOERROR;
}

hpint32 hotobject_read_bytes(HPAbstractReader *super, hpbytes *bytes)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	const HotObject *ob = hotobject_get(self);
	bytes->ptr = ob->var.val.bytes.ptr;
	bytes->len = ob->var.val.bytes.len;

	return E_HP_NOERROR;
}

hpint32 hotobject_read_type(HPAbstractReader *super, HPType *type)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	const HotObject *ob = hotobject_get(self);
	*type = ob->var.type;

	return E_HP_NOERROR;
}

hpint32 hotobject_read_hpbool(HPAbstractReader *super, hpbool *val)
{
	HotObjectReader* self = HP_CONTAINER_OF(super, HotObjectReader, super);
	const HotObject *ob = hotobject_get(self);
	*val = ob->var.val.b;

	return E_HP_NOERROR;
}

hpint32 hotobject_read_vector_item_end(HPAbstractReader *super, hpuint32 index)
{
	char str[1024];
	hpuint32 str_len = 0;
	hpint32 count;

	count = index;
	do
	{
		str[str_len++] = '0' + count % 10;
		count/=10;
	}while(count > 0);
	return hotobject_read_field_end(super, str, str_len);
}


hpint32 hotobject_reader_init(HotObjectReader* self, const HotObject *hotobject)
{
	memset(self, 0, sizeof(HotObjectReader));
	self->stack_num = 0;
	self->stack[self->stack_num].ho = hotobject;
	++(self->stack_num);

	self->super.read_struct_begin = hotobject_read_struct_begin;
	self->super.read_struct_end = hotobject_read_struct_end;
	self->super.read_vector_begin = hotobject_read_vector_begin;
	self->super.read_vector_end = hotobject_read_vector_end;
	self->super.read_field_begin = hotobject_read_field_begin;
	self->super.read_field_end = hotobject_read_field_end;

	self->super.read_type = hotobject_read_type;
	self->super.read_vector_item_begin = hotobject_read_vector_item_begin;
	self->super.read_vector_item_end = hotobject_read_vector_item_end;
	self->super.read_bytes = hotobject_read_bytes;
	self->super.read_double = hotobject_read_double;
	self->super.read_int64 = hotobject_read_hpint64;
	self->super.read_bool = hotobject_read_hpbool;

	return E_HP_NOERROR;
}
