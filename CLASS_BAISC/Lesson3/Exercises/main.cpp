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

1. 2D ��ǥ�� ǥ���ϴ� Ŭ������ ����� ���ô�.
x ��ġ
y ��ġ
���������� �Ÿ��� ��ȯ�ϴ� �Լ�
( x, y ) ���·� ����ϴ� �Լ�


*/