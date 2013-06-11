#ifndef _H_XMATH
#define _H_XMATH

#include "xbase.h"
#include "typedef.h"

//��ʼ��xmath������10^6���ڵ�������ŷ������
//�ٶ��е����
XAPI int xmath_init();

//a*b % n
XAPI hpuint64 mulmod(hpuint64 a, hpuint64 b, hpuint64 n);

//a^b %n
XAPI hpuint64 powermod(hpuint64 a,hpuint64 b, hpuint64 n);

//���Լ��
XAPI hpuint64	gcd(hpuint64 a, hpuint64 b);

//ŷ������
XAPI int euler(int n);

//��������
XAPI int	rabin_miller(hpuint64	n);

//�����ֽ�
XAPI hpuint64 rho(hpuint64 n);

//a * x + b * y = 1
XAPI void extendgcd(hpint64	a,hpint64	b,hpint64	*x,hpint64	*y, hpint64 *d);

//ax+bx=n
//d��a,b�����Լ������ʾ��ռ���d����
//(tx,ty)���ص�һ��tx����0�Ľ�
//һ����С��Ϊ(tx+i*b/d,ty-i*a/d)  (0<=i<d)
//ty*d/a+1Ϊ�Ǹ�������ĸ���
XAPI int	equation(hpint64	a,hpint64	b,hpint64	n,hpint64	*tx,hpint64	*ty,hpint64	*d);

//��С������
XAPI hpint64 lcm(hpint64	a,hpint64	b);

//x=Ai(mod Mi)
//����C �� A1 (mod M1)��C �� A2 (mod M2)��
//��C = A1 + X1M1����ôX1M1 �� A2 - A1 (mod M2)��
//����չŷ������㷨���X1��Ҳ�����C��
//��M = lcm(M1, M2)����ô�����������̾Ϳ��Ա�C�� �� C (mod M)���档
//����ֱ��ֻʣ��һ�����̡�
//������[0,m1)����Ψһ�Ľ�a1������ռ��Ϊ1��
//a1+i*m1Ϊ���н�(m1Ϊm[]����С������)
XAPI int	china(hpint64	*a,hpint64 *m,int	tail,hpint64	*a1,hpint64	*m1);

#endif//_H_XMATH
