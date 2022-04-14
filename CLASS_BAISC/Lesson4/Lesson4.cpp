/*


기본생성자
	-생성자를 제공하지 않으면 자동으로 만들어 주는 형태
	 
	 예제>

		class MyClass
		{
			int mX;
		public:
			MyClass(int value) <<
			{
				mX = value;
			}
		
		};
		
		
		int main()
		{
			MyClass c1; // 컴파일 오류,, 이유는? 생성자를 만드는 순간 기본생성자를 제공하지않는다
			//매겨변수가 달라져버렸다 기본생성자를 만들어줘야한다
		}
		


	
	
	-매개 변수가 없는 아무것도 안하는 형태







---------------------------------------------------------------------------------------------------------

#초기화

int a = 2;

-복사초기화
	>> 복사초기화가 일어나는 과정은 
	   램에 정수형타입의 공간을 만들고(4바이트) 그공간에 a라는 이름을 붙여주고
	   정수형 타입의 공간을 만들어 2라는 값을 넣는다(임시 r-value)
	   그리고 2의 값이 들어간 정수형타입을 a라는 이름을 붙여준 공간에 복사한다

int b(2);

-직접초기화
	클래스 생성자와 비슷함
	int형타입에 b를 만들고 생성자의 매개변수 2로 초기화되는형태

int c{2};

-유니폼초기화
	직접초기화와 같다

int d = {2};

-유니폼복사초기화
	int형 객체d를 만들고 int형 생성자 2를 매개변수로 생성해서
	객체 d 로 복사한다



일반 로컬변수는 램에 만들어진다
매개변수는 램 또는 레지스터에 만들어진다

그래서 유니폼초기화와 직접초기화가 더 빠르다


------------------------------------------------------------------------------------------

#클래스 초기화

Quest q1 = Quest();
-복사초기화
	Quest타입으로 이름없는 객체가 만들어진다 (r-value)
	Quest타입으로 q1의 객체가 만들어진다
	이름없는 객체가 q1의 객체로 복사가 이루어진다


Quest q2(1); 혹은 Quest q2;
-직접초기화
	생성자를 호출 해서 객체를 직접 초기화 하는형태

Quest q3{1};
-유니폼 초기화
	직접초기화와 같음
	이름없는 객체에 바로 이름을 붙여주는 형태 
	그래서 직접초기화와 유니폼초기화가 더빠르다

Quest q4 = { 1 };
-유니폼 복사 초기화
	Quest q4 = { 1 }; 는 Quest q4 = Quest { 1 }; 형태와 같다
	Quest타입끼리 복사를 기대하는것
	즉
	이름없는 Quest객체가 만들어지고 매개변수 1을 대입(이름없는객체 - r vlaue) 임시값
	Quest 객체 q4가 만들어짐
	이름 없는 객체의 임시값이 q4라는 객체로 복사


---------------------------------------------------------------------------------------

#포인터 초기화

int* p{};
	p라는 변수는 정수를 가르키는 포인터 타입으로
	nullptr로 초기화 한다

MyClass* pClass{};
	포인터 변수는 객체가 아니기때문에 {}은 생성자를 호출한다는 의미가 아닌
	포인터를 null로 초기화 한다는 의미이다

MyClass* pClass2 { new MyClass { } };
	MyClass를 동적으로 기본생성자를 이용해서 생성한다음에
	그 포인터를 pClass2에 대입 유니폼 초기화
	포인터 변수는 객체가 아니다

	new MyClass { } 에서 {}은 생성자를 호출하는 의미이지만
	MyClass* pClass2 { } 에서 {}은 객체가 아닌 포인터 변수이기때문에
	new MyClass{} 값으로 초기화 한다는 의미





클래스 초기화 
예제코드>>



class MyClass
{
public:
	int mValue1{ 1 };
	int mValue2{ 1 };

	MyClass(int value1)
	{
		mValue1 = value1;
		mValue2 = 0;
	}

};


int main()
{
	MyClass c1; // 기본생성자가 없기때문에 컴파일 에러 
	MyClass c2{ 1 };  // 1 과 0의 출력
	MyClass c3{ 2,3 }; // 기본생성자가 없기때문에 컴파일 에러

	std::cout << c1.mValue1 << " " << c1.mValue2 << std::endl;
	std::cout << c2.mValue1 << " " << c2.mValue2 << std::endl;
	std::cout << c3.mValue1 << " " << c3.mValue2 << std::endl;

}
// 직접 만든 생성자를 지우면 3개다 문제없이 컴파일이 가능하다
// 출력값은 첫번째는 1과 1 두번째는 1과 2 세번째도 2와 3이 된다
// {}초기화 안에 값으로 멤버들을 바꿔준다



#POD (Plain Old Data)

struct vs class
구조체와 클래스의 차이

	- Standard Layout Type
		C 언어와 같은 구조의 타입
		int , float , double...
	
	- Trivial Type
		사용자가 정의한 간단한 타입
		struct


class ClassA
{

};

class ClassB
{
public:
	ClassB();
}

ClassA는 POD
ClassB는 POD가 아니다
이유는?
기본생성자가 둘다 있지만 
ClassB의 기본생성자는 안 내부에서 무언가 연산을 한다면 그건 POD가 아니다
그 차이?

POD의 장점
	-복사가 빠르다

클래스가 POD가 되려면 기본생성자가 암시적으로 쓰여야 한다



즉

예제코드>>



class MyClass
{
public:
	int mValue1{ 1 };
	int mValue2{ 1 };

	MyClass(int value1)
	{
		mValue1 = value1;
		mValue2 = 0;
	}

};


int main()
{
	MyClass c1; // 기본생성자가 없기때문에 컴파일 에러
	MyClass c2{ 1 };  // 1 과 0의 출력
	MyClass c3{ 2,3 }; // 기본생성자가 없기때문에 컴파일 에러

	std::cout << c1.mValue1 << " " << c1.mValue2 << std::endl;
	std::cout << c2.mValue1 << " " << c2.mValue2 << std::endl;
	std::cout << c3.mValue1 << " " << c3.mValue2 << std::endl;

}

이 예제 코드는 생성자를 생성함으로써
POD가 아니게 되고 멤버에 직접 초기화가 불가능 해진다? 라고 이해하면 될라나

즉 기본생성자가 암시적으로 존재하려면 생성자가 없어야한다 
그런 Class는 POD라 할수있다

데이터의 걊을 변동여지를 주지 않으면 POD


------------------------------------------------------------------------------



class ClassA
{
public:
	ClassA()
	{
		std::cout << "[ClassA] 생성" << std::endl;
	}
};
class ClassB
{
	ClassA mA;

public:
	ClassB()
	{
		std::cout << "[ClassB] 생성" << std::endl;
	}
};

int main()
{
	ClassB myClass;
}

// 출력값은 [ClassA] 생성 [ClassB] 생성

즉 A가 먼저 만들어지고 그다음에 B가 만들어진다
이유는?

ClassB의 객체가 먼저 만들어지고
객체안에 멤버변수를 만들어야하는데
ClassB 의 멤버변수는 ClassA 가 있기때문에
ClassA를 먼저 생성하고 그다음에 ClassB가 만들어진다

즉 멤버가 먼저 만들어진다!! 중요!


-----------------------------------------------------------------------------------------

:: 범위 해결 연산자


class ClassB
{
	class ClassA
	{
	public:
		ClassA()
		{
			std::cout << "[ClassA] 생성" << std::endl;
		}
	};
	ClassA mA;

public:
	ClassB()
	{
		std::cout << "[ClassB] 생성" << std::endl;
	}
};

int main()
{
	ClassB::ClassA c1;   // 클래스 안에 클래스를 생성하려면 :: 범위 해결 연산자로 호출해야한다
}
단 classA를 private으로 한다면 범위 해결 연산자로도 불가능하다


---------------------------------------------------------------------------------------------------

#인스턴스 초기화 - 효율적인 방법
멤버 초기화 리스트
<생성자> : <멤버초기화1> , <멤버초기화2>,....


예제코드>>

class Quest
{
private:
	const int mID; 
	int mExp;

public:
	Quest(int id, int exp) : mID{ id }, mExp{ exp }{}; <<<<< 멤버초기화 리스트
	// 생성자에서 멤버들을 초기화
	//멤버변수가 이렇게 초기화 한다면 상수여도 초기화 가능함
	//단 멤버변수에 직접적으로 초기화 한다면 생성자로 초기화가 불가능 

	void Print()
	{
		std::cout << "mID : " mID << ". Exp : " << mExp << std::endl;
	}
};

int main()
{
	Quest q1(1,100);
	q1.Print();
}













*/

class Quest
{
private:
	int mID;
	int mExp;
public:
	Quest(int id, int exp) : mID{ id }, mExp{ exp }{};
	
	void Print()
	{
		std::cout << "mID : " mID << ". Exp : " << mExp << std::endl;
	}
};

int main()
{
	Quest q1(1,100);
	q1.Print();
}
