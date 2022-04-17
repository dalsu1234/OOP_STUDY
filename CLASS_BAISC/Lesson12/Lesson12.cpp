/*

#함수 오버라이딩
function overriding
	부모의 멤버 함수를 자식이 재정의하는것
	상속 + 멤버 함수의 시그니쳐가 같아야함


#가상함수

	자식이 overriding 할것을 기대하는 함수
	즉 가상함수는 기반 클래스에 선언해야하는것
	
	상속 + 부모 클래스의 멤버함수

예제>>
#############################################


부모클래스

class Animal
{
.....


virtual void Sound(); // 가상함수 
//이러면 기반클래스의 함수를 호출을 넘기고
//파생 클래스의 오버라이딩 함수를 호출하게 된다

}


기반 클래스

class Dog
{
	.......

	void Sound() override; 
	// 뒤에 override를 붙여주면되는데
	// 사실 override를 안붙여도 기반클래에서 조건만 만족하면
	// 실행되는데는 문제 없다 그냥 명시적으로 확실하게 보이게 하려고
	// 
}

######################################################################

예제2>>

class ClaasA
{
public:
	void Func1()
	{
	}

	virtual void Func2()
	{
	}

}


class ClassB : public ClassA
{
public:
	void Func1()
	{
	}

	void Func2()
	{
	}
}




int main()
{
	ClassA* a = new ClassA;
	ClassB* b = new ClassB;

	a->Func1(); // 일반 멤버 함수
	a->Func2(); // 가상 멤버 함수
	b->Func1(); //      멤버 함수 오버라이딩
	b->Func2(); // 가상 멤버 함수 오버라이딩
	
	ClassA::func1이 호출되고
	ClassA::func2이 호출되고
	ClassB::func1이 호출되고
	ClassB::func2이 호출된다

	
	/////////////////////////////////////////



	ClassA* p = b;
	p->Func1();   // ClassA 멤버 함수
	p->Func2();   // ClassA의 가상멤버함수 -> 즉 ClassB의 오버라이딩함수
	// 이러면 어떻게 호출될까?
	그래서
	ClassA::func1이 호출되고
	ClassB::func2가 호출된다
}




class ClassC : public ClassB
{
public:
	void Func1()
	{
	}

	void Func2()
	{
	}
}

이렇게 추가한다면

int main()
{
	ClassA* p = new ClassC;

	p->Func1(); 
	p->Func2();

	이러면 어떻게 호출이 될까

	ClassA::func1이 호출되고
	ClassC::func2가 호출된다

	class ClassC : public ClassB 라고 해도
	ClassB의 기반은 ClassA

	###########################
	!! p의 실제 타입을 봐야한다
	!! new ClassC; 이기때문에
	!! 두번째 호출은 ClassC가 된다
}






////////////////////////////////



다형성 최종 정리

다형성
상속 & 포인터로 존재한다
정확하게는 

가상함수(상속) & 포인터
로 존재한다



class Character
{
public:
	virtual void Attack();
}

class Warrior : public Character
{
void Attack(); // 근접 공격
}

class Archer : public Character
{
void Attack(); // 원거리 공격
}

class Wizard : public Character
{
void Attack(); // 마법 공격
}

Chararcter* party[4]{new Warrior, new Archer, new Wizard,new Warrior};

Character*로 
한번에 묶어서 관리가 가능해진다

직업에 맞는 고유한 공격도 가능하고


다형성은 
virtual 가상함수
Character* 포인터
로 이루어진


###########################################################################

#binding

타입 객체 값 변수의 3가지 기본구성요소

이중에


객체와 값을 바인딩해주는 과정


---------------------
변수는 
객체와 값

함수는 
선언과 정의를
바인딩해주는 과정
연결해주는 과정





바인딩에는 크게 두가지 종류가 있다

early binding               vs                late binding

static binding              vs               dynamic binding

컴파일 binding              vs               런타임 binding


타입정보는 대부분 런타임때 알수있다



예제

int main()
{
	ClassA* a = new ClassA;
	ClassB* b = new ClassB;

	ClassA* p = new ClassB;

	p->Func1();
	p->Func2();

	여기서 컴파일 바인딩과 런타임 바인딩은 누구??

	p의 실제타입을 알려면 런타입밖에 없다
	즉
	인스턴스가 어떤 타입이냐는 런타임에서만 알수있다

	가상 함수는 컴파일때 바인딩이 일어나는게 아니라
	런타임때 일어난다

}

########################################################################


early binding               vs                late binding

static binding              vs               dynamic binding

컴파일 binding              vs               런타임 binding

타입정보


실제로 만들어지는 오브젝트는
멤버변수만 존재

함수들은 코드에 따로 존재한다

이걸 하나의 객체로 작동하려면 이걸 서로 바인딩해주는 과정이 필요하다

파생 클래스가
가상함수가 없으면
기반 함수와 파생함수끼리 서로 1대1로 연결해주면 되기때문에
컴파일에서 일어나지만

하지만 가상함수가 존재한다면
컴파일에서 알수있는 방법이 없기때문에
런타임에서 바인딩을 해준다

컴파일때는 일단 가상함수를 따로 보관하는 가상함수테이블에 바인딩해주고
가상함수테이블에는 각 오버라이딩함수들을 모아놓는다 쌓아놓는다 스택구조

그리고 런타임때 가상테이블에 쌓인 오버라이딩 함수를 찾아 연결해준다


ClassA 
ClassB
ClassC
순서로 만들어지고

가상함수테이블에
A::가상함수
B::오버라이딩함수
C::오버라이딩함수
이런식으로 쌓아둔다
여기까지가 컴파일때 일어나는 과정이고

런타임때
이런식으로 호출되면
그때 바인딩해서 실행이되는것이다
p->Func();  <<여기서 이제 가상함수테이블에서 찾아서 실행해준다

##########################################################################################

소멸자


Animal* p = new Dog();

delete p;

이런식이면

Animal의 소멸자가 먼저 불리기때문에 Dog의 소멸자는 불려지지않는다
이러면 메모리 누수가 생김

해결법

######################################

virtual ~소멸자();

기반 클래스에 소멸자를 가상함수로 만들어준다

이러면 기반 클래스에 있는 소멸자는 무시하고
먼저 Dog의 소멸자를 부르고 
그다음에 올라와서 Animal의 소멸자를 불러낸다


그래서
만약에 상속 구조로 클래스를 만든다면

반드시
!!!!!기반클래스의 소멸자는 가상소멸자
매우 중요!!!

###########################################

가상생성자는 없는이유

이미 인스턴스의 정의와 선언에서 
명시되어있기때문에 필요가없다
어차피 기반클래스의 생성자를 호출하고 파생클래스 생성자를 호출하니깐
불필요하다
###########################################

하지만 자기자신을 복사 하고싶다면??


일반함수로 자기자신을 복사하는 함수를 만든다

class Dog : public Animal
{

public:

	Animal* Clone()
	{
		return new Dog(*this);
	}
	// 쉽게 설명하자면 여기서 *this 는 나 자기자신이고
	// clone함수의 반환값 Animal* 인이유는
	// Animal* p = new Dog(); 에서 Animal*타입으로 인스턴스를 만들었기때문이고
	// 라기보단 다형성을 유지하기위해 그런듯?
	// 기반클래스에 가상함수를 만드기 위함
	// new Dog 는 Dog의 실제 객체를 만들어야 하기때문에 이런표현식을 사용하게 된다 
}   // 복사할 본인의 객체가 Dog기때문에 new Dog인거지머

class Animal 
{
	virtual Animal* Clone();  // 그리고 여기서 가상함수선언
}


이런식으로 만들어준다

#################################################


LinkedList 클래스를 만드세요.
여기에서 상속된 Stack, Queue를 만들어 보세요.

상속 & 다형성의 개념을 적극 활용!!

*/