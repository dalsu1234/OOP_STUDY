#include <iostream>
/*

class Point2D
{
	int x;
	int y;
public:
	void Print();
};


int main()
{
	Point2D pt1;
	pt.x = 1; // ��������� private�̶� ���� �Ұ����ϴ�
}

�ذ���
get/set
*/



class Point2D
{
	int mX;
	int mY;
public:
	void Set(int x, int y); // Set  �̷������� private�� ��������� ���� ����
	
	int GetX(); // Get
	
	void Print();
};

void Point2D::Set(int x, int y)
{
	mX = x;
	mY = y;
}

int Point2D::GetX()
{
	return mX;
}

int main()
{
	Point2D pt1;

	pt1.Set(1, 1);
}

