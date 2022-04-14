/*

상수 변수
	const int NAME_LENGTH { 10 };

상수 매개변수
	void PrintInfo(const Queue& queue);

상수 반환값
	const Stack& GetStack();

상수 멤버함수
	class MyClass
	{
		int GetValue() const;
	}


==========================================================



연습문제>

클래스 선언과 정의를 .h .cpp로 분리하세요!

1. 2D 좌표를 표현하는 클래스를 만들어 봅시다.
x 위치
y 위치
원점에서의 거리를 반환하는 함수
( x, y ) 형태로 출력하는 함수



2. 10명의 학생을 가지고 있는 학급을 클래스로 만들어 봅시다. 학생도 클래스로 만들어야 합니다.
	학생
이름
번호
성적


	학급
학년
반
학생 10명
전체 학급의 학생 목록을 출력하는 함수
전체 학급의 총점을 구하는 함수


-------------------------------------------------------------------------------------

기본생성자와 소멸자
constructor / destructor



생성자
	: 인스턴스가 생성될 때 (자동적으로)호출되는 특별한 멤버함수
	-Rule
		- 클래스 이름과 동일한 이름의 함수
		- 반환 타입이 없다
		- 매개변수는 필요에따 추가할수있다

	-용도
		- 매개변수 초기화

소멸자
	: 인스턴스가 사라질 때 (자동적으로)호출되는 특별한 멤버함수
	-Rule
		- 클래스 이름과 동일한 이름에 접두어(~) 함수
		- 반환 타입이 없다
		- 매개변수도 없다

생성자와 소멸자는 대부분 Public에서 사용한다


예제1>

class MyClass
{

public:
	MyClass(); // 기본생성자

	~MyClass(); // 소멸자

}

int main()
{
	MyClass c;    <<<<< 여기서 기본생성자가 호출된다

	std::cout << "  " << std::endl;
} <<<<< 여기서 소멸자를 호출한다


예제2>
class Quest
{
	int mID;
	int mExp;

public:
	// 기본생성자
	Quest()
	{
		mID = 0;
		mExp = 0;
	}

	// 생성자 오버로딩
	Quest(int id, int exp)
	{
		mID = id;
		mExp = exp;
	}

	void Print()
	{
		std::cout << "QuestID : " << mID << std::endl; // 여기서 mID는 인스턴스것이다
		std::cout << "EXP : << mExp << std::endl;
	}

}

int main()
{
	Quest q1; // 기본생성자  
	//기본생성자는 ()를 사용하면 안된다  
	// q1() 으로 하면 오류가 난다 이유는? :  컴파일러가 함수 선언인지 호출인지 모호해한다
	
	Quest q2(10, 100); // 생성자 오버로딩

	q1.Print();
	q2.Print();

}

*/