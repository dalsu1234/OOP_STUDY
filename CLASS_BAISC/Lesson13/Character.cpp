#include <iostream>
#include "Character.h"

Character::Character() : mHP{0}
{
	std::cout << "ĳ���� ����" << std::endl;
}

Character::~Character()
{
	std::cout << "ĳ���� ����" << std::endl;
}

void Character::Attack() const
{
	std::cout << "�����Լ� ����" << std::endl;
}
