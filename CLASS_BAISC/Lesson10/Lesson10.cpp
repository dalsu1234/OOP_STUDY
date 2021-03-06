/*

#Realtionship
#관계성


1.
is-part=of : 결합

2.
has-a  : 소유/집단화

3.
use-a  :사용/ 연관

4.
is-a   : 특수화 혹은 일반화
		 상속

------------------------------------------------------------------------------
1.
A is-part-of B

- A는 B의 일부 구성요소
- A는 한번에 하나의 객체에만 존재
- A는 B에 의해서 관리
- A는 B의 존재를 모른다

예)
노트북 = B

노트북 안에 CPU = A


클래스 예제
################################################

class CPU
{

}


class NoteBook
{
	CPU mCPU; // A is-part-of B // 멤버변수화
}


NoteBook a,b,c,d,e;  // 노트북에 의해 멤버변수 mCPU는관리된다

################################################

2.
A has-a B
 - B는 A의 일부 구성요소
 - B는 한번에 여러 오브젝트에 소속
 - B는 A에 의해 관리되지않음
 - B는 A의 존재를 모른다


예)

B는 키보드나 마우스같은 외부기기

A는 노트북


클래스예제
###################################################

class CPU
{

}
class KeyBoard
{

}

class NoteBook
{
	CPU mCPU;			 // is part of 멤버변후화
	KeyBoard* mKeyboard; // has-a // 멤버 포인터 변수화 // 포인터 타입 // 
	- B는 A의 일부 구성요소
};


NoteBook mac,gram;
Keyboard logitech;

gram->mKeyboard = &logitech;
gram->mac = &logitech;

-B는 한번에 여러 오브젝트에 소속

노트북에 인스턴스가 없어져도 키보드와는 상관이없다
- B는 A에 의해 관리되지않음


###################################################

3.
A use-a B

 - B는 A와 관련이 없다
 - B는 한번에 여러오브젝트에 소속 될수도 있다
 - B는 A에 의해 관리되지않음
 - B는 A의 존재를 알수도있고 몰라도 된다


예)

B가 노트북

A 사용 유저, 사람

설명하기 애매하다

has-a와 구분이 안된다

관계성의 차이만 있지 코딩으로는 차이가 없다


###################################################

결국은 1번 파트오브는 멤버변수
2번 3번은 멤버포인터 변수의 차이로 구분할수있다!!
이것만 기억하면됨!!
클래스 멤버변수가 일반변수냐 포인터변수냐 로 구분

###################################################



가장중요한

4.
A is-a B

 - A는 B의 상속
 - A는 특수화 // B는 일반화
 - 상위개념 하위개념

 A는 노트북 브랜드 (apple , lg , hp)
 B는 노트북




 4가지 종류를 간략하게 정리하자면
클래스의 일반 멤버변수는 클래스가 생성되면 같이 생성되고
클래스가 소멸되면 같이 소멸되지만

포인터 멤버변수는 클래스가 생성될때 생성될수도 있고 아닐수도있고
소멸될때도 같이 소멸될수도 있고 아닐수도 있다


#######################################################

is - a 관계

클래스 예제

#######################################################

class Cat
{
private:
	int mAge;

public:
	int mWeight;

public:
	void Meow();
};


class Dog
{
private:
	int mAge;

public:
	int mWeight;

public:
	void Bark();
};


이 두가지 클래스가 같은 기능이 있고 특수화 즉 고유 특징을 가지는 것이 있다

이걸 나눠서 클래스를 작성하는게 특수화와 일반화


일반화 : mAge; , mWeight;

특수화 : 강아지의 Bark(); 와 고양이의 Meow()

가 되겠다.

#######################################################

파생//상속


파생

 기반 클래스(동물) // 파생 클래스 (고양이, 강아지)

상속

 부모 클래스 // 자식 클래스

#######################################################

class Animal
{
protected:  // private면 파생클래스가 접근할방법이 읍다
	int mAge;
	int mWeight;

};

class Cat : public Animal // Animal클래스가 그대로 클래스안에 복사해 들어간다라고 생각하면됨
{
public:
	void Meow();
};

class Dog : public Animal
{
public:
	void Bark();
};

int main()
{

}

----------------------------------------------------------------------------------------------

표현식>

class 파생클래스 : [virtual] [접근제한자] 기반클래스, ...
{

};

class 자식 : [virtual] [접근제한자] 부모, ...
{

}




#접근제한자>

- private
클래스 내부에만 공개

- public
모두 공개

- protected
상속에게만 공개 나머지는 비공개

##############################################################################################################

멤버              public 상속            protected 상속          private 상속

public            public                 protected               private

protected         protected              protected               private

private           접근불가               접근불가                접근불가



##############################################################################################################


예제)











*/