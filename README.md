TData
======
**��ƽ̨�����Ե�������������!**

- cmake ����cmake���̵Ľű��ļ�
- source Դ����
- tutorial ʹ������
- language ���԰�

����ͷ���
==========
������� �� [https://github.com/randyliu/TData/issues](https://github.com/randyliu/TData/issues)

��װ
====
###TData

1.��װ[Bison](http://www.gnu.org/software/bison/) 2.7.1

		Windows
			��װCygwin��ѡ�������Bison���ߡ�
		Linux
			apt-get install bison

		OS X
			./configure
			make
			make install

2.��װ[re2c](http://sourceforge.net/projects/re2c/) 0.13.5

		Windows
			����re2c.exe�ŵ����ص�һ���ļ����У� �����ļ���·������path��������
		Linux
			apt-get install re2c
		OS X
			./configure
			make
			make install

3.��װ[CMake](http://www.cmake.org/) 2.8.11.1

4.����[TData](https://github.com/randyliu/TData)Դ����

		git clone https://github.com/randyliu/TData

5.CMake���ɹ����ļ�

		ʹ�÷�����ο� �� [http://www.cmake.org/](http://www.cmake.org/)

6.����

		Windows
			��Microsoft Visual Studio�� ������롣
		Linux
			make
		OS X
			make

7.��װ

		Windows
			��Microsoft Visual Studio��ִ��INSTALL��Ŀ��
		Linux
			make install
		OS X
			make install

8.���û�������

		����TDATA_HOME��������Ϊ��װĿ¼
		Windows
			�½�һ����������TDATA_HOME=C:\Program Files\TData
		Linux
			export TDATA_HOME=/usr/local
		OS X
			export TDATA_HOME=/usr/local
