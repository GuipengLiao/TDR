HotPot
======
**����һ������� �����кܶ���������!**

- hotpot ��ƽ̨ģ�飬 ֧��Windows Linux OSX��
- hotprotocol ������Э��ģ�飬 ֧��C, Php, ObjC��
- hotscript ������ʾ����Ľű����ԣ� ֧��C��php��չ��

����ͷ���
==========
������� �� [https://github.com/randyliu/HotPot/issues](https://github.com/randyliu/HotPot/issues)

��װ
====
### C��İ�װ

1.��װ[Bison](http://www.gnu.org/software/bison/) 2.4.1

	Windows
		��װ[Cygwin](http://www.cygwin.com/)��ѡ�������Bison���ߡ�
	Linux
		apt-get install bison
	OS X
		./configure
		make
		make install

2. ��װ[re2c](http://sourceforge.net/projects/re2c/) 0.13.5
	Windows
		����re2c.exe�ŵ����ص�һ���ļ����У� �����ļ���·������path��������
	Linux
		apt-get install re2c
	OS X
		./configure
		make
		make install

3. ��װ[CMake](http://www.cmake.org/) 2.8.11.1

4. ����[HotPot](https://github.com/randyliu/HotPot)Դ����

	git clone https://github.com/randyliu/HotPot

5. CMake���ɹ����ļ�

	ʹ�÷�����ο� �� [http://www.cmake.org/](http://www.cmake.org/)

6. ����

	Windows
		��Microsoft Visual Studio�� ������롣
	Linux
		make
	OS X
		make

7. ��װ

	Windows
		��Microsoft Visual Studio��ִ��INSTALL��Ŀ��
	Linux
		make install
	OS X
		make install

8. ���û�������

	����HOTPOT_DIR��������Ϊ��װĿ¼
	Windows
		�½�һ����������HOTPOT_DIR=C:\Program Files\HotPot
	Linux
		export HOTPOT_DIR=/usr/local
	OS X
		export HOTPOT_DIR=/usr/local

### [PHP](http://www.php.net/manual/zh/index.php)�İ�װ
**��װ**

	source\hotscript\php\ext\hotscriptĿ¼����һ����׼��php��չ, �밴��php���ṩ�ķ������а�װ��
**php.ini**

	��php.ini�����HotPot��װĿ¼ hotpot.dir="C:\Program Files\HotPot"

### hotprotocol-java�İ�װ
	������

### hotprotocol-cocoa�İ�װ
	������
