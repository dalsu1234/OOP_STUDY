#include <iostream>
#include "Dog.h"



Dog::Dog() : mBreed{ HUSKY }
{}

Dog::~Dog()
{
}

/*
BREED Dog::GetBreed() const // ���� :: ������?? BREED�� ��� ������ �˼�������
{
	return mBreed;
}

*/

Dog::BREED Dog::GetBreed() const // �̷��� �ٲ��ش� DOG::BREED
{
	return mBreed;
}

void Dog::SetBreed(BREED breed) // �׷� ���� �ִ� �Ű����� breed��? �� �������ɱ�?
{								
	mBreed = breed;
} // DogŬ���� �ȿ� �Լ��� �ִ°Ŵ� ����ִ� BREED���� �˼����ִµ�
// ���� ������ ��� �ִ� BREED�� ��� ���Ѱ��� �˼�������
// �׳� �տ� Dog:: �� �����ϱ� ��� ���Ѱ��� �˼��ֱ⶧�� �̶�� �����ϸ� �ɷ���..
// ���Ƿ� ����Ҷ��� BREED ��� ������ �˼��� �����ϱ� 
// �׷��� �ݵ�� ��� �����ִ��� �˷�����Ѵ�


void Dog::Roll()
{
	std::cout << "...." << std::endl;
}
