#include <iostream>
#include "Dog.h"



Dog::Dog() : mBreed{ HUSKY }
{}

Dog::~Dog()
{
}

/*
BREED Dog::GetBreed() const // 에러 :: 이유는?? BREED가 어디에 속한지 알수가없다
{
	return mBreed;
}

*/

Dog::BREED Dog::GetBreed() const // 이렇게 바꿔준다 DOG::BREED
{
	return mBreed;
}

void Dog::SetBreed(BREED breed) // 그럼 여기 있는 매개변수 breed는? 왜 괜찮은걸까?
{								
	mBreed = breed;
} // Dog클래스 안에 함수가 있는거니 어디에있는 BREED인지 알수가있는데
// 위에 오류는 어디에 있는 BREED는 어디에 속한건지 알수가없다
// 그냥 앞에 Dog:: 가 있으니깐 어디에 속한건지 알수있기때문 이라고 생각하면 될려나..
// 정의로 사용할때는 BREED 어디에 속한지 알수가 없으니깐 
// 그래서 반드시 어디에 속해있는지 알려줘야한다


void Dog::Roll()
{
	std::cout << "...." << std::endl;
}
