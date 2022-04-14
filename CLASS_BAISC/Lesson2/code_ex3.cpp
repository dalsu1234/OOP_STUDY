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
	pt.x = 1; // 멤버변수가 private이라 접근 불가능하다
}

해결방법
get/set
*/



class Point2D
{
	int mX;
	int mY;
public:
	void Set(int x, int y); // Set  이런식으로 private한 멤버변수에 접근 가능
	
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

