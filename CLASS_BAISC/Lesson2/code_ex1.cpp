#include <iostream>
// ����>>
class Student
{
	int mScore;
	int mNumber;

public:
	void Ranking()
	{
	}
	void Print()
	{
		std::cout << mScore << std::endl;
	}
};
// ====== Ŭ���� ======

int main()
{
	Student test1, test2; // Ŭ���� �ν��Ͻ�

	test1.Print();
}