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

1. 2D ��ǥ�� ǥ���ϴ� Ŭ������ ����� ���ô�.
x ��ġ
y ��ġ
���������� �Ÿ��� ��ȯ�ϴ� �Լ�
( x, y ) ���·� ����ϴ� �Լ�


2. 10���� �л��� ������ �ִ� �б��� Ŭ������ ����� ���ô�. 
�л��� Ŭ������ ������ �մϴ�.


�л�
	-�̸�
	-��ȣ
	-����


�б�
	-�г�
	-��
	-�л� 10��
	-��ü �б��� �л� ����� ����ϴ� �Լ�
	-��ü �б��� ������ ���ϴ� �Լ�


*/