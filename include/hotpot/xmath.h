#ifndef _H_XMATH
#define _H_XMATH

#include "xbase.h"
#include "typedef.h"

//��ʼ��xmath������10^6���ڵ�������ŷ������
//�ٶ��е����
XAPI int xmath_init();

//a*b % n
XAPI uint64 mulmod(uint64 a, uint64 b, uint64 n);

//a^b %n
XAPI uint64 powermod(uint64 a,uint64 b, uint64 n);

//���Լ��
XAPI uint64	gcd(uint64 a, uint64 b);

//ŷ������
XAPI int euler(int n);

//��������
XAPI int	rabin_miller(uint64	n);

//�����ֽ�
XAPI uint64 rho(uint64 n);

//a * x + b * y = 1
XAPI void extendgcd(int64	a,int64	b,int64	*x,int64	*y, int64 *d);

//ax+bx=n
//d��a,b�����Լ������ʾ��ռ���d����
//(tx,ty)���ص�һ��tx����0�Ľ�
//һ����С��Ϊ(tx+i*b/d,ty-i*a/d)  (0<=i<d)
//ty*d/a+1Ϊ�Ǹ�������ĸ���
XAPI int	equation(int64	a,int64	b,int64	n,int64	*tx,int64	*ty,int64	*d);

//��С������
XAPI int64 lcm(int64	a,int64	b);

//x=Ai(mod Mi)
//����C �� A1 (mod M1)��C �� A2 (mod M2)��
//��C = A1 + X1M1����ôX1M1 �� A2 - A1 (mod M2)��
//����չŷ������㷨���X1��Ҳ�����C��
//��M = lcm(M1, M2)����ô�����������̾Ϳ��Ա�C�� �� C (mod M)���档
//����ֱ��ֻʣ��һ�����̡�
//������[0,m1)����Ψһ�Ľ�a1������ռ��Ϊ1��
//a1+i*m1Ϊ���н�(m1Ϊm[]����С������)
XAPI int	china(int64	*a,int64 *m,int	tail,int64	*a1,int64	*m1);

#endif//_H_XMATH
