#include <iostream>
#include "Point2D.h"
int main()
{
	Point2D point;
	point.Set(5, 3);
	point.Print();
	std::cout << point.DistancePoint() << std::endl;
}



/*

1. 2D 좌표를 표현하는 클래스를 만들어 봅시다.
x 위치
y 위치
원점에서의 거리를 반환하는 함수
( x, y ) 형태로 출력하는 함수


*/