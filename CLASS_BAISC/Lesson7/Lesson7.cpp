/*

# 연산자 오버로딩

예제>>
######################################################################
class Myclass
{
	반환타입 operator +(피연산자);

	int operator+(int x);
	int operator+(Myclass x); // 다른 인스턴스를 받아서 현재 인스턴스와 더한다
};

######################################################################


1. 모든 피연산자가 기본타입 (int, floar, bool) 이라면 내장 연산자(사칙연산)를 사용

2. 피연산자가 클래스, 구조체와 같이 사용자 타입

	a. 오버로딩된 연산자

	b. 기본타입으로 형변환 시도 -> 1번


일반 함수 형태
	operator+(lhs, rhs);

멤버 함수 형태
	operator+(rhs); // 현재 인스턴스가 좌측 그래서 우측피연산자만 받으면 된다



예제 >>
######################################################################

class Point2D
{
private:
	int mX;
	int mY;
public:
	Point2D(int x, int y) : mX{ x }, mY{ y }{};

	void Print()
	{
		std::cout << "(" << mX << "," << mY << ")" << std::endl;
	}

	friend Point2D operator+(Point2D pt1, Point2D pt2);  // 친구 함수를 이용한 연산자 오버로딩
};

Point2D operator+(Point2D pt1, Point2D pt2) // 연산자 오버로딩 // 콜바이밸류를 값참조로 변경할수있다
{
	Point2D result{ 0,0 };
	result.mX = pt1.mX + pt2.mX;
	result.mY = pt1.mY + pt2.mY;
	return result;
}

// 하지만 값참조로 변경하면 여기서 문제가 생긴다
// 이유는 ?? 무명객체!!
int main()
{
	Point2D pt1(2, 3) , pt2 (4,5) , pt3(2,1);
	pt1.Print();

	Point2D pt4 = pt1 + pt2 + pt3;
	// pt1 + pt2를 먼저 계산하고 그 값을 + pt3를 계산해서
	// pt4에 값을 넣는다
	// 여기서 연산자 오버로딩을 값참조로 변경하면
	// 임시값이 무명객체로 주소를 참조할수없어서
	// 컴파일 오류가된다
}

######################################################################

#무명객체

변수에 이름을 붙이는건 나중에 다시 사용하기 위해서이다
이름이 없다면 다시 사용할수가 없다

예제 >>
######################################################################

class MyClass
{
	int mValue;
public:
	MyClass(int n) : mValue{n}
	{
		std::cout << "[MyClass] : " << mValue << std::endl;
	}
	~MyClass()
	{
		std::cout << "		[MyClass] : " << mValue << std::endl;
	}
	friend MyClass operator+(MyClass c1, MyClass c2);
}

MyClass operator+ (MyClass c1, MyClass c2)
{
	return MyClass(c1.mValue + c2.mValue);
}

int main()
{
	MyClass c1{1}, c2{2}, c3{3};

	MyClass c4 = c1 + c2 + c3; // 연산자 오버로딩의 매개변수를 참조로 받으면 컴파일 오류가 생긴다
}

######################################################################
출력값은
[MyClass] : 1	 << c1
[MyClass] : 2	 << c2
[MyClass] : 3	 << c3
[MyClass] : 3    << 이녀석이 무명객체 c1+c2의 값이다 이름이 없다
					// 이름이 없는 r-value // 이름이 없기때문에 참조가 불가능하다!!
[MyClass] : 6	 << (c1+c2) + c3의 값   : c4
	[MyClass] : 3
	[MyClass] : 3
	[MyClass] : 2
	[MyClass] : 1
	[MyClass] : 6
	[MyClass] : 3
	[MyClass] : 2
	[MyClass] : 1


그렇다면 참조값으로 매개변수를 바꾸고 싶다면 해결책은?

MyClass operator+ (const MyClass& c1, const MyClass& c2)
{
	return MyClass(c1.mValue + c2.mValue);
}

이런식으로 매개변수를 상수로 해준다
이게 바로 우측값 참조




######################################################################


#멤버 함수 형태
>>
######################################################################
Point2D operator+(Point2D rhs)
{
	Point2D result{0,0};
	result.mX = this->mX + rhs.mX;
	result.mY = this->mY + rhs.mY;

	return result

}
######################################################################
private인 rhs.mX나 mY의 값에 접근할수있는 이유는?

!!캡슐화는 인스턴스 단위가 아니라 클래스 단위 이다

!!!즉 클래스 내부에서 사용하는건 가능하다

######################################################################

Point2D operator+(Point2D& rhs) // 참조형
{
	Point2D result{0,0};
	result.mX = this->mX + rhs.mX;
	result.mY = this->mY + rhs.mY;

	return result

}
######################################################################
멤버 함수 형태는 왜 참조형으로 바꿔도 컴파일 에러가 나지 않는가?

이유는?

pt1 + pt2 + pt3

pt1.+ (pt2) // 이런 형태

그럼 pt1 + pt2 값은 무명객체일텐데

멤버함수형태가
무명객체 + (pt3) 의 형태이다
그래서 문제 없이 컴파일 가능

하지만 pt1 + (pt2 + pt3)는 컴파일 오류가 난다
pt1 + 무명객체 의 형태이기때문에 오류가 난다

그래서 const를 붙여주자 안전하게

Point2D 타입에 객체를 생성 하고 매개변수 (rhs)를 받는 형태인건가?
그리고 Point2D의 타입을 반환하고?
음.. 모르겟다

######################################################################

++ 단항연산자 오버로딩

일반 함수형태
	operator ++(매개변수);

멤버 함수 형태
	operator ++();



*/
