#include <iostream>
#include "Point2D.h"
#include "Student.h"
int main()
{
	Point2D point;
	point.Set(5, 3);
	point.Print();
	std::cout << point.DistancePoint() << std::endl;


	Room stu;
	stu.SetClassRoom();
	stu.ResultValue();
	stu.Print();

}



/*

1. 2D 좌표를 표현하는 클래스를 만들어 봅시다.
x 위치
y 위치
원점에서의 거리를 반환하는 함수
( x, y ) 형태로 출력하는 함수


2. 10명의 학생을 가지고 있는 학급을 클래스로 만들어 봅시다. 
학생도 클래스로 만들어야 합니다.


학생
	-이름
	-번호
	-성적


학급
	-학년
	-반
	-학생 10명
	-전체 학급의 학생 목록을 출력하는 함수
	-전체 학급의 총점을 구하는 함수


*/