#include "Student.h"
#include <iostream>

int Room::ResultValue()
{
	mTotalScore = 0;
	for (int i = 0; i < LENGTH_STU; i++)
	{
		mTotalScore += mStudent[i].mScore;
	}
	return mTotalScore;
}

void Room::Print() const
{
	std::cout << mYear << " �г�" << mRoom << " ��" << std::endl;
	for (int i = 0; i < LENGTH_STU; i++)
	{
		std::cout << std::endl;
		std::cout << "�̸� : " << mStudent[i].mName << std::endl;
		std::cout << "��ȣ : " << mStudent[i].mNum << std::endl;
		std::cout << "���� : " << mStudent[i].mScore << std::endl;
		std::cout << std::endl;
	}
	std::cout << "==================" << std::endl;
	std::cout << "���� : " << mTotalScore << std::endl;
	std::cout << "==================" << std::endl;
}
void Room::SetClassRoom()
{
	std::string name;
	int n{};
	int score{};
	std::cout << "�г� : ";
	std::cin >> mYear;
	std::cout << "�� : ";
	std::cin >> mRoom;
	std::cout << "==================" << std::endl;

	for (int i = 0; i < LENGTH_STU; i++)
	{
		std::cout << "�̸� : ";
		std::cin >> name;
		mStudent[i].mName = name;
		std::cout << "��ȣ : ";
		std::cin >> n;
		mStudent[i].mNum = n;
		std::cout << "���� : ";
		std::cin >> score;
		mStudent[i].mScore = score;
		std::cout << "==================" << std::endl;

	}
}
