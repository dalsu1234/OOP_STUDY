#include <iostream>

struct Point2D
{
	int x;
	int y;

	void Print(); // 선언
	
};

void Point2D::Print() // 정의 
{
	std::cout << x << " , " << y << std::endl;
}
// :: 범위 해결연산자  (이항 연산자)
// 범위 해결연산자로 클래스 범위 밖에서 정의가 가능
// 멤버함수가 private여도 클래스 밖에서 정의는 문제없다

int main()
{
	
}