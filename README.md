HotPot
======
**����һ������� �����кܶ���������!**

- HotPlatform ��ƽ̨����ģ�飬 ֧��Windows,Linux,OS X��
- HotProtocol ������Э��ģ�飬֧��C,PHP,ObjC��
- HotLib ���� �ʷ��������� �����봦���
- HotData �����������ԡ�
- HotScript �ı������ߡ�

����ͷ���
==========
������� �� [https://github.com/randyliu/HotPot/issues](https://github.com/randyliu/HotPot/issues)

��װ
====
###HotPot-C

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

3.��װ[Python](http://www.python.org/) 3.3.2

4.��װ[CMake](http://www.cmake.org/) 2.8.11.1

5.����[HotPot](https://github.com/randyliu/HotPot)Դ����

		git clone https://github.com/randyliu/HotPot

6.CMake���ɹ����ļ�

		ʹ�÷�����ο� �� [http://www.cmake.org/](http://www.cmake.org/)

7.����

		Windows
			��Microsoft Visual Studio�� ������롣
		Linux
			make
		OS X
			make

8.��װ

		Windows
			��Microsoft Visual Studio��ִ��INSTALL��Ŀ��
		Linux
			make install
		OS X
			make install

9.���û�������

		����HOTPOT_DIR��������Ϊ��װĿ¼
		Windows
			�½�һ����������HOTPOT_DIR=C:\Program Files\HotPot
		Linux
			export HOTPOT_DIR=/usr/local
		OS X
			export HOTPOT_DIR=/usr/local

###HotScript-PHP
����PHP�ĸ�����Ϣ�� ��ο�[PHP�ֲ�](http://www.php.net/manual/zh/index.php)

1.��װ

		source/hotscript/php/ext/hotscriptĿ¼����һ����׼��php��չ, �밴��php���ṩ�ķ������а�װ��

2.php.ini

		���HotPot��װĿ¼ hotpot.dir="C:\Program Files\HotPot"
		���HotScript�Ĺ���Ŀ¼ hotscript.workingdir = d:/


###HotProtocol-Java
		������

###HotProtocol-Cocoa
		������
