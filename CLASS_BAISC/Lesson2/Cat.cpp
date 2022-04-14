#include <iostream>
#include "Cat.h"


void Cat::Meow()
{
	std::cout << "Meow.." << std::endl;
}

int Cat::GetAge() const
{
	return mAge; // 인스턴스의 멤버
}
