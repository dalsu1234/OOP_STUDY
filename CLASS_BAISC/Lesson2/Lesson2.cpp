/*

struct Point3D
{
	int x;
	int y;
	int z;
};


class Point3D
{
public:
	int x;
	int y;
	int z;

	void Print();
};

C++ : ����ü�� ��� ����� public�� Ŭ������ ����



struct : ��� �����鸸 �����ϴ� �ڏ�����
class  : ��� �Լ��� �ʿ��� ��ü



------------------------------------------------------------

���
const

const int COUNT = 1000;

void F(const int x);

Ŭ���� ���


�������Լ�










*/



#include <iostream>
#include "Cat.h"


int mian()
{
	Cat nacho;
	nacho.Meow();

	nacho.GetAge(); // �� �ν��Ͻ��� ����������� ���� ������ �ʴ´�.
	// �������Լ��̱⶧����

	//�����Ҵ�
	Cat* pCancho = new Cat;
	pCancho->Meow(); // �����Ҵ��̱⶧���� .�̾ƴ϶� ->�� �����ؾ��Ѵ�
	delete pCancho; //delete ��������
}