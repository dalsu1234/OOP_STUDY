/*
const
#클래스 상수


예제>>
#################################################################################
class MyClass
{

public:
	int mValue1;
	int mValue2;

	MyClass()
	{
	}
	MyClass(int v1, int v2) : mValue1{ v1 }, mValue2{ v2 }
	{
	}

	void SetValue1(int x)
	{
		mValue1 = x;
	}

	void Print()
	{
		std::cout << mValue1 << ", " << mValue2 << std::endl;
	}

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}


int main()
{
	MyClass c1; // 기본 생성자로 만들어진 c1 객체

	MyClass c2(2, 2); // 인트형 매개변수 2개를 사용하는 생성자로 만들어진 c2객체

	MyClass c3{ 3,3 }; // 유니폼 초기화를 사용해서 초기화한 c3

	c1.Print(); 
	c2.Print();
	c3.Print(); // 각각 출력은 1,1   2,2   3,3
}

######################################################################################

상수로 선언한 객체

int main()
{
	const MyClass c1;

	const MyClass c2(2, 2); 

	const MyClass c3{ 3,3 }; 

	c1.Print(); // 여기서 컴파일 오류
	c2.Print(); // 이유는?
	c3.Print(); //
}

#컴파일 오류의 이유

  상수객체란 
  객체의 내용이 바뀌면 안된다라는 뜻
  
  초기화는 가능하다
  초기화 이후에는 값을 바꿀수 없다
  
  하지만 Print() 함수안에는 값을 변경할수있는 가능성이 존재
  누군가 코드를 Print()안에 값을 변경하는 코드를 작성한다면??
  
  그래서 향후 문제가 생길수있는 여지가 있기때문에
  컴파일에서 오류가 생기는것
  
#해결책

>> Print() const;
  상수 멤버 함수를 사용하면된다.
  
  이 의미는 Print() 함수 안에 값은 변경하지않는다는 보장을 해준다
  
  상수를 객체로 사용한다고 해도
  또는 Private로 보호한다고 해도
  클래스안에서 함수로 언제든지 그 멤버값에 접근하고 변경할수있기때문에
  이럴때는 상수함수를 사용하여서 그안에 값을변경하지 못하도록
  작성하는것이 중요하다


-------------------------------------------------------------------------------


static
#정적

void DoSomething()
{
	static int x = 1;
}

스태틱 변수에 특징

-한번 생성되면 스코프를 벗어나도 프로그램 종료가 될때까지 존재한다.

예제>>
##################################################################

class MyClass
{
public:
	static int mValue;
};

int main()
{
	MyClass c1;  // 클래스는 이처럼 인스턴스화 해야지 만들어진다
	c.mValue; // 에러// 정의되지않은 멤버 // 왜그럴까?

}

######################################################################

static 멤버

클래스 멤버에 static은 조금 다른 의미를 가진다

한번 생성되는건 일반적인 static과 같지만

한번 만들어지면 끝까지 존재하려면
인스턴스것이 되면 안된다
이유는?? 

#정적 멤버 변수
	인스턴스 소유가 아닌 , 클래스 소유
	정적멤버는 클래스 소유가 된다

	그래서 다른이름으로 클래스 변수라고도 부른다

	개인적인 생각으로는
	인스턴스소유가 된다면 정적멤버변수는 그 인스턴스에 의해
	존재하거나 소멸할수도있기때문에 그런거같다 // 생성자/소멸자


	변수가 실제로 존재하는것은 선언이 아닌 정의
	클래스는 그래서 인스턴스화 하지않는이상 존재하는것이 아니다


######################################################################
class MyClass
{
public:
	static int mValue; // << 선언  즉 정의가 필요하다
};

int MyClass::mValue = 0;  // << 정의    // 이런식으로

######################################################################

  정적 멤버 변수는 인스턴스와 상관이 없어야 한다
  그래서 클래스와 연관되어야 하는데
  클래스는 정의로 존재하지않는다
  그래서 정적 멤버 변수는 이런식으로 정의를 해야한다



# 정적 멤버 표기

######################################################################

class MyClass
{
public:
	static int mValue; 
};

int MyClass::mValue = 0;

int main()
{
	MyClass c1;

	MyClass c2; 
	
	
	// 별로 좋은 표기법이 아니다
	//c1.mValue = 1;
	//c1.mValue = 10;

	//std::cout << c1.mValue << std::endl;
	//std::cout << c2.mValue << std::endl;
	//컴파일이나 사용에는 문제가 없지만

	// 옳바른 표기법

	MyClass::mValue = 1; // 독자적으로 클래스에 존재하는 변수라서
	// 이런식으로 명확하게 작성한다
	
	std::cout << MyClass::mValue << std::endl;

}
######################################################################

// 만약 클래스 안에
static int mValue; 를 
static int mValue = 0; 식으로 정의한다고 해도 상수가 아닌이상 불가능하다
// 컴파일에러


######################################################################
class MyClass
{
public:
	static int mValue;
};

int MyClass::mValue = 0;


######################################################################
// 반드시 위처럼 분리해서 정의하고 선언해야한다


예제 1
######################################################################

class Counter
{
public:
	static int sCount;

	void Count()
	{
		std::cout << sCount << std::endl;
		sCoutn++;
	}

};

int Counter::sCount { 1 };

######################################################################

예제 2

class MyClass
{
public:
	static int sCount;

	MyClass()
	{
		sCount++;
	}

	~MyClass()
	{
		sCount--;
	}

}

int MyClass::sCount { 0 };

int main()
{
	std::coout << MyClass::sCount << std::endl;
}

MyClass가 몇번 출력된건지 알수있는 식?

int main()
{
	MyClass c1;
	
	{
		for(int i = 0; i < 5; i++)
		{
			MyClass c2;
		} // 여기서 c2 소멸자가 호출
		
		MyClass c3;
	}// 여기서 c3 소멸자가 호출

	std:cout << MyClass::sCount << std::endl;

}// 여기서 c1 소멸자 호출

그래서 출력값은 1 이된다 

######################################################################


---------------------------------------------------------------------------------------


# 정적 멤버 함수
static member function (class function)

정정 멤버 변수와 같이 
인스턴스에 소속된것이 아니라
클래스에 속한다

예제 1
######################################################################

class MyClass
{
public:
	static int sCount;

	void Order()
	{
		sCount++;
	}

};

int MyClass::sCount { 0 };

int main()
{
	MyClass c1, c2 , c3;

	c1.Order();
	c2.Order();
	c3.Order();  // static 함수를 만들면 이런식으로 여러개 만들필요가 없다

}


class MyClass
{
public:
	static int sCount;

	static void Order() // 정적 멤버 함수
	{
		sCount++;
	}

};

int MyClass::sCount { 0 };

int main()
{
	MyClass c1, c2 , c3;

	MyClass::Order();
	MyClass::Order();
	MyClass::Order(); // 이런식으로 사용 가능

	std::cout << MyClass::sCount << std::endl;

	//인스턴스가 몇개가 되던 상관이없다
}

######################################################################

----------------------------------------------------------------------


# friend
	
	A가 B를 친구로 지정하면 B는 A의 모든 멤버를 알수있다
	하지만 A는 B를 모른다

	빵셔틀이라고 생각하면 될듯?

	내정보를 공개할 대상을 지정하는것


예제 1
######################################################################


class Sword
{
private:
	int mDamage;

public:
	Sword(int dmg) : mDamage {dmg}
	{

	}
	
};

class Warrior
{
public:
	void Attack(Sword& sword);
	{
		std::cout << "칼을 휘둘러" << sword.mDamge << std::endl; 
		// 컴파일 에러 //왜냐면 sword.mDamge는 private 이니깐
		// 해결방법은? 일반적으로 getter를 사용하면 된다
		// 하지만 friend를 사용한다면?

	}

};

int main()
{
	Sword shortSword(10);
	Warrior player1;

	player.Attack(shorSword);
}



#
friend 사용 예제
##############################################################


class Sword
{

	friend class Warrior;  // 이런식으로 사용  // 친구 클래스 ###
	
	friend void UpgradeSword(Sword& sword);    // 친구 함수   ###

private:
	int mDamage;

public:
	Sword(int dmg) : mDamage {dmg}
	{

	}

};

class Warrior
{
public:
	void Attack(Sword& sword);
	{
		std::cout << "칼을 휘둘러" << sword.mDamge << std::endl;
		//위에 프렌드를 선언  하면 private라도 접근할수있다

	}

};

void UpgradeSword(Sword& sword) 
{
	sword.mDamage *= 2;
	std::cout << "강화 성공 : " << sword.mDamge <<std::endl;
}

int main()
{
	Sword shortSword(10);
	Warrior player1;

	UpgradeSword(shortSword);

	player.Attack(shorSword);
}


######################################################################

친구 클래스와 친구 함수 두가지가 존재
친구 변수는 존재할수가 없다

friend void UpgradeSword(Sword& sword)
{
	sword.mDamage *= 2;
	std::cout << "강화 성공 : " << sword.mDamge <<std::endl;
}

// 이런식으로 선언과 정의롤 같이 사용할수도 있다
// 클래스 안에 있다고 해서 이건 클래스것이 아니다
// 전역함수에 있으니 이건 전역함수이다
// 클래스와 전혀 상관없다
######################################################################

- 친구 클래스
- 친구 함수 예제를 봤다면

	친구 멤버함수도 존재한다

친구 멤버함수 예제>>
######################################################################

# 친구 멤버 함수

class Sword
{

friend void Warrior::Attack(Sword& sword); // 친구 멤버 함수 선언 ##
// 하지만 컴파일이 안된다
// 이유는?? Warrio라는 클래스의 선언은 아래쪽에 있어서
// 순서 문제
// 그렇다면 Warrior 클래스를  위에 선언한다고 가능한건 아니다
// 이유는 매개변수에 Sword& 클래스를 필요로 하는데 아래쪽에 있어서
// 불가능하다
// # 해결법?
// 선언과 정의를 분리해서 사용한다
// 전방 선언을 하고 정의를 아래에 작성하면 된다


private:
	int mDamage;

public:
	Sword(int dmg) : mDamage {dmg}
	{

	}

};

class Warrior
{
public:
	void Attack(Sword& sword);
	{
		std::cout << "칼을 휘둘러" << sword.mDamge << std::endl;
		//위에 프렌드를 선언  하면 private라도 접근할수있다

	}

};

void UpgradeSword(Sword& sword)
{
	sword.mDamage *= 2;
	std::cout << "강화 성공 : " << sword.mDamge <<std::endl;
}

int main()
{
	Sword shortSword(10);
	Warrior player1;

	UpgradeSword(shortSword);

	player.Attack(shorSword);
}

######################################################################

# 해결법



class Warrior
{

public:
	void Attack(Sword& sword);

};


class Sword
{


private:
	int mDamage;

public:
	Sword(int dmg) : mDamage {dmg}
	{

	}

friend void Warrior::Attack(Sword& sword); // 여기서 선언을 하고 ##

};


void Warrior::Attack(Sword& sword)  // 여기서 정의를 한다 ##
{
	std::cout << "칼을 휘둘러" << sword.mDamge << std::endl;
}

######################################################################

하지만 friend 를 잘 사용하지않는다

	개념이 어렵고
	사용이 복잡하다 (선언과 정의)
	캡슐화 규칙에서 벗어난다

하지만 유용하게 쓸수있는경우가 한가지 있다

바로 Operator Overloading

연산자 오버로딩이 있다

*/