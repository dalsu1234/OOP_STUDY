#include <iostream>

struct Point2D
{
	int x;
	int y;

	void Print(); // ����
	
};

void Point2D::Print() // ���� 
{
	std::cout << x << " , " << y << std::endl;
}
// :: ���� �ذῬ����  (���� ������)
// ���� �ذῬ���ڷ� Ŭ���� ���� �ۿ��� ���ǰ� ����
// ����Լ��� private���� Ŭ���� �ۿ��� ���Ǵ� ��������

int main()
{
	
}