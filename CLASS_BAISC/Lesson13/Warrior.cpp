#include<iostream>
#include "Warrior.h"
Warrior::Warrior()
{
	std::cout << "������ ����" << std::endl;
}

Warrior::~Warrior()
{
	std::cout << "������ ����" << std::endl;
}

void Warrior::Attack() const
{
	std::cout << "������ ����" << std::endl;
}

void Warrior::DoubleSlash() const 
{
	std::cout << "������ ���� ����" << std::endl;
}
