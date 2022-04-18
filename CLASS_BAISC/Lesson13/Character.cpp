#include <iostream>
#include "Character.h"

Character::Character() : mHP{0}
{
	std::cout << "캐릭터 생성" << std::endl;
}

Character::~Character()
{
	std::cout << "캐릭터 삭제" << std::endl;
}

void Character::Attack() const
{
	std::cout << "가상함수 공격" << std::endl;
}
