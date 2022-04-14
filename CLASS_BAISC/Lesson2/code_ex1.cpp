#include <iostream>
// 예제>>
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
// ====== 클래스 ======

int main()
{
	Student test1, test2; // 클래스 인스턴스

	test1.Print();
}