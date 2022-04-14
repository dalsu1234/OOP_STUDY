#pragma once
#include <iostream>

const int LENGTH_STU{3};
class Student
{
public:
	std::string mName;
	int mNum;
	int mScore;
};


class Room
{
	int mYear;
	int mRoom;
	int mTotalScore;
	Student* mStudent = new Student[LENGTH_STU];

public:
	void Print() const;
	void SetClassRoom();
	int ResultValue();

};
