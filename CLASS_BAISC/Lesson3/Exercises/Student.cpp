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
	std::cout << mYear << " 학년" << mRoom << " 반" << std::endl;
	for (int i = 0; i < LENGTH_STU; i++)
	{
		std::cout << std::endl;
		std::cout << "이름 : " << mStudent[i].mName << std::endl;
		std::cout << "번호 : " << mStudent[i].mNum << std::endl;
		std::cout << "점수 : " << mStudent[i].mScore << std::endl;
		std::cout << std::endl;
	}
	std::cout << "==================" << std::endl;
	std::cout << "총점 : " << mTotalScore << std::endl;
	std::cout << "==================" << std::endl;
}
void Room::SetClassRoom()
{
	std::string name;
	int n{};
	int score{};
	std::cout << "학년 : ";
	std::cin >> mYear;
	std::cout << "반 : ";
	std::cin >> mRoom;
	std::cout << "==================" << std::endl;

	for (int i = 0; i < LENGTH_STU; i++)
	{
		std::cout << "이름 : ";
		std::cin >> name;
		mStudent[i].mName = name;
		std::cout << "번호 : ";
		std::cin >> n;
		mStudent[i].mNum = n;
		std::cout << "점수 : ";
		std::cin >> score;
		mStudent[i].mScore = score;
		std::cout << "==================" << std::endl;

	}
}
