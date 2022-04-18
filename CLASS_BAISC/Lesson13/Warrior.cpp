#include<iostream>
#include "Warrior.h"
Warrior::Warrior()
{
	std::cout << "워리어 생성" << std::endl;
}

Warrior::~Warrior()
{
	std::cout << "워리어 삭제" << std::endl;
}

void Warrior::Attack() const
{
	std::cout << "워리어 공격" << std::endl;
}

void Warrior::DoubleSlash() const 
{
	std::cout << "전사의 더블 공격" << std::endl;
}
