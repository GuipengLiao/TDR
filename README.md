HotPot
========================
**������һ������� ����ܶ����߰������������!**

- hotpot ��ƽ̨ģ�飬 ֧��Windows Linux OSX��
- hotprotocol ������Э��ģ�飬 ֧��C, Php, ObjC��
- hotscript ������ʾ����Ľű����ԣ� ֧��C��php��չ��

### ����ͷ���
������� �� [https://github.com/randyliu/HotPot/issues](https://github.com/randyliu/HotPot/issues)

###��װ
1����װBison
		http://www.gnu.org/software/bison/
		�汾2.4.1

		Windows:
			��װCygwin, http://www.cygwin.com/
			ѡ�������Bison����
		Linux:
			apt-get install bison
		OS X:
			./configure
			make
			make install			

2����װRE2C
		http://sourceforge.net/projects/re2c/
		�汾0.13.5

		Windows:		
			����re2c.exe�ŵ����ص�һ���ļ����У� �����ļ���·������path��������
		Linux:
			apt-get install re2c
		OS X:
			./configure
			make
			make install

3����װCMake
		http://www.cmake.org/
		�汾��2.8.11.1

4������HotPotԴ����
		git clone https://github.com/randyliu/HotPot

5��CMake���ɹ����ļ�
		http://www.cmake.org/
		�ο�CMakeʹ�÷���

6������
		Windows:
			��Microsoft Visual Studio�� ������롣
		Linux:
			make
		OS X:
			make

7����װ
		Windows:
			��Microsoft Visual Studio��ִ��INSTALL��Ŀ��
		Linux:
			make install
		OS X:
			make install

8�����û�������
		����HOTPOT_DIR��������Ϊ��װĿ¼
		Windows:
			�½�һ����������HOTPOT_DIR=C:\Program Files\HotPot
		Linux:
			export HOTPOT_DIR=/usr/local
		OS X:
			export HOTPOT_DIR=/usr/local

����PHP��չ�İ�װ
1����װPHP��չ
		php�汾5.5.1		
		source\hotscript\php\ext\hotscriptĿ¼����һ����׼��php��չ�� ��װ��ο�php�ĵ�
		http://www.php.net/manual/zh/install.php

2������PHP
		��php.ini�����HotPot��װĿ¼:
			hotpot.dir="C:\Program Files\HotPot"

����hotprotocol-java�İ�װ
	������

�ġ�hotprotocol-cocoa�İ�װ
	������
