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

C++ : 구조체는 모든 멤버가 public인 클래스와 같다



struct : 멤버 변수들만 존재하는 자룍구조
class  : 멤버 함수가 필요한 객체



------------------------------------------------------------

상수
const

const int COUNT = 1000;

void F(const int x);

클래스 상수


상수멤버함수










*/



#include <iostream>
#include "Cat.h"


int mian()
{
	Cat nacho;
	nacho.Meow();

	nacho.GetAge(); // 이 인스턴스의 멤버변수들은 절대 변하지 않는다.
	// 상수멤버함수이기때문에

	//동적할당
	Cat* pCancho = new Cat;
	pCancho->Meow(); // 동적할당이기때문에 .이아니라 ->로 접근해야한다
	delete pCancho; //delete 잊지말고
}