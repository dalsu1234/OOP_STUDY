#pragma once
class Cat
{
private:
	int mAge;

	//상수 멤버 변수
	const int LEG_COUNT = 4;


public:
	
	void Meow();
	
	
	//상수 멤버 함수
	//const void Meow(); 이건 반환값이 상수라는 뜻이기때문에 멤버함수가 상수라는 뜻은 아니다
	
	int GetAge() const;
	// 상수 멤버함수의 옳바른표현
	// 즉 상수 멤버함수는 인스턴스가 상수
	// 일반적으로 상수멤버함수는 getter함수에서 많이 사용한다
};

