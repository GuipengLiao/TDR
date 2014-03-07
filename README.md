TData
======
**֮ǰ������C���Ե�һ��ͷ�ļ�item.h�ﶨ����һ���ṹ��item_table_s��ʾ��Ϸ�ĵ���**

	enum item_type_e
	{
		e_crystal,
		e_ectype,
		e_other,
	};

	union item_limit_u
	{
		uint32 level;
		uint32 mapid;
		uint32 gold;
	};

	const uint32 ITEM_MAX_LIMIT = 10;
	struct item_table_s
	{
		uint64 id;
		string name;
		item_type_e type;
		vector<item_limit_u> limit_list;
	};

**��ʱ��Ҫ��mysql�ж�ȡ������ϵĵ���**

	�˴�ʡ�����ɷ�������ȡmysql���ݿ�Ĵ��롣


**��ʱ��Ҫ������Э���������߷��͸��ͻ���**

	�˴�ʡ�������з��������л����󵽻���Ĵ��롣
	�˴�ʡ�������пͻ��˷����л����浽�ṹ��Ĵ��롣

**��ʱ��������Ҫ��ȡ�߻�ͬѧ��д�ĵ��߱���ԴExcel�ļ�**

	�˴�ʡ�������з�������ȡExcel���롣
	�˴�ʡ�������пͻ��˶�ȡExcel���롣

**��ʱ��ά��վ��Ҫһ��xml�����ĵ���**

	�˴�ʡ�������ж���ת��Ϊxml�Ĵ��롣

**��ʱͻȻ����֮ǰд������ת�������Ȼ���ú����ƣ�**

**����ɥ�Ĳ�����ǲ߻��ո�����޸ĵ��߱�� �����ֵð����д����޸�һ�顭��**


**����TData֮��, ֻ��Ҫ��item.h����Ϊitem.td�� Ȼ������tdata -gen all item.td�Ϳ��԰�ǰ�����е����Ĵ������ɳ����ˣ�**

TData��˵���ĵ�, �������� �� [https://github.com/TDorm/TData/wiki](https://github.com/TDorm/TData/wiki)

����
====
	�������������⣬ ʹ��C���Ա�д�� ����֧��Windows, Linux, OSXƽ̨��

����ͷ���
==========
������� �� [https://github.com/randyliu/TData/issues](https://github.com/randyliu/TData/issues)

��װ
====
- ���ڿ�ƽ̨����Ҫ�� ���Ȱ�װ[CMake](http://www.cmake.org/), ���ڴ��뱾��û���κ����������԰�װ���̼�Ϊ�򵥡�

	shell> mkdir build
	shell> git clone https://github.com/TDorm/TData TData
	shell> cd build
	shell> cmake ../TData
	shell> make
	shell> sudo make install
