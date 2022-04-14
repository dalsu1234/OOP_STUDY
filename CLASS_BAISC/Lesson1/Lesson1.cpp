
/*
C++클래스
객체(Object) : 클래스 (CLASS)로 만들어진 하나의 인스턴스(instance)
클래스(class)
	- 상태(state)
		- 멤버변수 (member variable) - C++
		- 필드(field)				 - C# , JAVA
	- 행동(Behaviour)
		- 멤버함수 (member funtion) - C++
		- 메서드 (Method)			- C#, JAVA
-------------------------------------------------------------------------
OOP
1. Object(객체)
2. Class(클래스)
3. Encapsulation(캡슐화)
	: Information Hiding - 정보은닉
		- 불필요한 정보를 숨겨서 쉽게 사용
		- 보안 : 사용자가 모르게 숨기는 정보
4. Inheritance(상속,파생)
	: 상속 - 부모(Parent) 클래스 , 자식(Child) 클래스
	: 파생 - 기반(Base) 클래스 , 파생(Derived) 클래스
5. Polymorphism(다형성)
-------------------------------------------------------------------------
Constructor(생성자) / Destructor(소멸자)
	:객체가 만들어질때 자동적으로 생성자가 사용, 소멸될때 소멸자가 사용
Static Member
	: 한번만 만들어지고 끝까지 유지되며 프로그램이 종료될때 없어진다
	: 정적 멤버 - 인스턴스와 상관없이 하나만 존재하는 멤버
Abstract Class
	: 추상클래스
	: 개념만으로 존재하는 클래스
	: 규격,규칙을 정하는 클래스?
Overloading vs Overriding
--------------------------------------------------------------------------------------
Class Declaration (클래스 선언)
class<이름>
{
[접근제한자:]
	<멤버1>
	<멤버2>
	......
} [인스턴스];
[] : 생략가능함
예제>
class Cat
{
private:
	int age;
private:
	char breed[20];
	char name[20];
public:
	void Meow();
};
Cat nacho;
-------------------------------------------------
Access Modifier (접근제한자 종류)
	-public
		클래스 내부/외부에서 사용 가능
		멤버함수에서 가능 인스턴스에서 가능
	-protected - 상속과 관련
	-private
		클래스 내부에서만 사용 가능
		멤버함수에서 가능 인스턴스에서 불가능
예제>
class Cat
{
public:
	int age;
private:
	int color;
	void Meow();
};
Cat nacho;
nacho.age = 3;
	<< 접근제한자가  public이라 클래스 밖에서도 접근이 가능
nacho.color = 1;
	<< 접근 제한자가 Private이라 클래스 내부에서만 접근이 가능
*/