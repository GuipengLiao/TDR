#ifndef _H_HP_MATH
#define _H_HP_MATH

#include "hotpot/hp_platform.h"

//��ʼ��xmath������10^6���ڵ�������ŷ������
//�ٶ��е����
HP_API hpint32 hp_math_init();

//a*b % n
HP_API hpuint64 hp_mulmod(hpuint64 a, hpuint64 b, hpuint64 n);

//a^b %n
HP_API hpuint64 hp_powermod(hpuint64 a,hpuint64 b, hpuint64 n);

//���Լ��
HP_API hpuint64	hp_gcd(hpuint64 a, hpuint64 b);

//ŷ������
HP_API hpint32 hp_euler(hpint32 n);

//��������
HP_API hpint32	hp_rabin_miller(hpuint64	n);

//�����ֽ�
HP_API hpuint64 hp_rho(hpuint64 n);

//a * x + b * y = 1
HP_API void hp_extendgcd(hpint64	a,hpint64	b,hpint64	*x,hpint64	*y, hpint64 *d);

//ax+bx=n
//d��a,b�����Լ������ʾ��ռ���d����
//(tx,ty)���ص�һ��tx����0�Ľ�
//һ����С��Ϊ(tx+i*b/d,ty-i*a/d)  (0<=i<d)
//ty*d/a+1Ϊ�Ǹ�������ĸ���
HP_API hpint32	hp_equation(hpint64	a,hpint64	b,hpint64	n,hpint64	*tx,hpint64	*ty,hpint64	*d);

//��С������
HP_API hpint64 hp_lcm(hpint64	a,hpint64	b);

//x=Ai(mod Mi)
//����C �� A1 (mod M1)��C �� A2 (mod M2)��
//��C = A1 + X1M1����ôX1M1 �� A2 - A1 (mod M2)��
//����չŷ������㷨���X1��Ҳ�����C��
//��M = lcm(M1, M2)����ô�����������̾Ϳ��Ա�C�� �� C (mod M)���档
//����ֱ��ֻʣ��һ�����̡�
//������[0,m1)����Ψһ�Ľ�a1������ռ��Ϊ1��
//a1+i*m1Ϊ���н�(m1Ϊm[]����С������)
HP_API hpint32	hp_china(hpint64	*a,hpint64 *m,hpint32	tail,hpint64	*a1,hpint64	*m1);

#endif//_H_XMATH
