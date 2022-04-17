/*

std::cout << x;

std::cout << y;

std::cout << x << y;



이렇게 오퍼레이터 연산자를 만들면 위와같이 표현이 가능하진다

std::ostream& operator << (std::ostrea& os, const Point& p)
{
	os << "(" << p.x << ". " << p.y << ")";
}

반환형에 주목

반환을 값이 아닌 참조로 했다

즉 들어온 인스턴스가 끝나면 std::ostream& 으로 반환 

(std::ostream& os , const Pont& p)

에서 여기에 os로 들어온 참조값인 인스턴스가 들어오고

{
	os << "(" << p.x << ". " << p.y << ")";
}

작업이 끝나고 끝난 인스턴스를 

std::ostream& operator 에

std::ostream& 으로 반환

os가 들어오고 안에 작업끝나고 그값을 std::ostream& 참조형으로 반환




즉
std::cout << x << y;
의 표현이 가능해지는건

std::cout << x 는 (std::ostream& os , const Pont& p)의 매개변수

std::cout 은 std::ostream& os의 매개변수
x는 const Pont& p 의 매개변수로

그리고 반환되는건 std::cout

(os라는 인스턴스가 들어와서 계산된값을 참조형태로 std::cout 으로 반환)

함수호출형태로 보면 되니깐

이런 표현이 가능하다

std::cout << x 가 std::cout 으로 되돌아 온다
그 되돌아온 std::cout이 다시 y와 매개변수로 다시 함수호출





이걸 응용하는 예제
########################################################################################


class Character
{
	void Move();
	void TurnLeft();
	void TurnRight();
}

Charater player;

player.Move();
player.TurnLeft();
player.TurnRight();
player.Move();

이렇게 사용하지말고

. 연산자 오버로딩을 만들지 않아도
player.Move().TurnLeft().TurnRight().Move(); 이런식으로 식이 가능하다


########################################################################################



class Character
{
public:
	Character& Move()
	{
		std::cout << "Move" << std::endl;
		return *this;
	}
	Character& TurnLeft()
	{
		std::cout << "TurnLeft" << std::endl;
		return *this;
	}
	Character& TurnRight()
	{
		std::cout << "TurnRight" << std::endl;
		return *this;
	}
}

########################################################################################

// 여기서 핵심은

Character& Move()
Character& TurnLeft()
Character& TurnRight()
의 반환값이 중요

사실 void로 사용해도 된다 

하지만

player.Move().TurnLeft().TurnRight().Move(); 의 식이 사용이 불가능하다

위에 설명했지만

std::cout << x << y;
는

std::cout << x가 반환이 되어서
그 반환된
반환된값 << y 의 식이 가능한거처럼

반환값을 참조값으로 하면
이런식으로 사용이 가능해진다

player.Move().TurnLeft().TurnRight().Move();

여기서 무명객체가 반환됨
그럼 무명객체가 몇번 만들어질까

참조값이기때문에 1번이라 생각하겠지만
1번도 안만들어진다 
참조형이니깐 기존의 인스턴스를 가져다가 쓰는거다
그 인스턴스를 계속 참조로 값을 받는다
새로 만들어지는 무명객체는 없는거다


player.Move().TurnLeft().TurnRight().Move();
(무명참조객체)
(무명참조객체).TurnLeft()
((무명참조객체)			)
((무명참조객체)			).TurnRight()
((무명참조객체)			)			)

요런너낌으로다가



만약 클래스 멤버 함수에서
Character Move() 참조값으로 받지않고 이렇게 받는다면
4개의 무명객체가 생기겠지



이런식으로 스트림 연산자의 개념으로
이렇게 확장이 가능하다

########################################################################################

----------------------------------------------------------------------------------------


#복사에 대하여


int x = 5; //복사 대입 초기화

int x(5) // 직접 초기화

int x{5} // 유니폼 초기화



#복사 대입 초기화

int x = 5;

메모리에 int형 타입에 x라는 이름을 붙이고

리터럴 5는 메모리에 인트형이고 값은 5가되는 객체를

x라는 객체에 복사를 한다



#직접 초기화

int x(5)

클래스에 생성자같은 느낌

메모리에
int형 타입에 리터럴 5값이 들어간 객체에
바로 x라는 이름을 붙여준다 그래서 직접초기화



#유니폼 초기화

직접초기화와 같다




이걸 클래스에 대입해서 생각해보면

#복사 대입 초기화

MyClass c = MyClass(5); // MyClass(5)라는 이름없는 객체를 c 인스턴스에 복사대입하기때문에 밑의 표현과 같은 표현이다
MyClass c = 5;

# 직접 초기화
MyClass c(5);

# 유니폼 초기화
MyClass c{5};






MyClass c = MyClass(5)
은 복사대입초기화

그러니깐 MyClass(5)의 무명객체가 c라는 인스턴스에게 복사 대입한다고 했지만
실제로는
MyClass(5)의 값에 c라는 이름을 바로 붙여준다

그럼 복사대입초기화가 아니네?
정작 복사가 일어나지 않는다

제대로 복사가 일어나려면??

MyClass c1(5);
MyClass c2(3);

MyClass c2 = c1; 


이거나

MyClass c1(5);
MyClass c2(c1);


클래스에선

이게 복사가 이루어 지는형태

MyClass c2(c1); 이걸 생성자 시그니처로 표현한다면??

MyClass (const MyClass& c1); 이런 모습이 된다


매개변수로 들어가는 식이 (const MyClass& c1) 인 이유는

참조로 들어가지않으면 또 복사가 이루어진다

c1을 c2에서 복사를 하기전에 매개변수로 한번 더 복사를 하기때문에
참조로 받아서 그걸 c2로 복사를 하면 되는데

매개변수로 복사하고 그걸 또 c2로 복사를 할필욘 없으니깐

그리고 const를 붙여주는이유는 
복사생성자가 이미 존재하고있다 보이지않지만
그 보이지 않는 복사생성자의 식이 이런식이기때문에
const를 사용
즉 복사생성자를 만들지않아도 컴파일러가 기본으로 제공한다
그타입이 MyClass (const MyClass& c1); 이렇게 생겼다라고 생각하면된다


이런 표현을 복사생성자라고 한다

#복사생성자

>>클래스 이름 (const 클래스& 인스턴스명)

기본적으로 만들어진다




MyClass c1{ MyClass{1} }
이건 복사생성자가 아니다
다시 말하지만 MyClass{1}은 이름이 없는 R-value (이름 없는 무명객체를 r value라 생각하면 될려나..)

MyClass c1{ 1 }; 
MyClass c2{ c1 };

이건 복사생성자

헷갈리지말자
복사대상이 r value면 복사가 이루어 지지않는다
l value여야 한다

######################################################################################

#기본생성자

클래스 이름 ();

#복사생성자

클래스 이름 (const 클래스이름& 인스턴스);

복사생성자는 반드시 L-value여야 한다

##################################################################################


#복사대입연산자


MyClass c1{ 1 };
MyClass c2;

c2 = c1; /// 여기가 복사 대입 연산자 =

복사대입연산자도 컴파일러가 기본으로 제공한다


MyClass& operaotr = (const MyClass& c);

void operaotr = (const MyClass& c);
반환값을 void로 해도 되지만 위에 말했던거처럼 

player.Move().TurnLeft().TurnRight().Move(); 이런식으로 사용이 불가능하다
먼가 기능적으로 제대로 사용하지 못하는 기분

그래서 MyClass& operaotr = (const MyClass& c); 요런 표현식을

복사대입연산자
return은 

MyClass& operaotr = (const MyClass& c)
{
	return *this;
}

식을 외우는것보다 왜 이런식이 되는건지 이해하는것이 중요하다


##################################################################################

#기본 생성자

#복사 생성자

#복사 대입 생성자

이 3가지 생성자는 컴파일러가 기본으로 제공하기때문에 만들어주지 않아도 사용가능하다

나머지 2가지가 더있는데 그건 차후에


##################################################################################

클래스에서 복사 주의점

동적할당을 할경우

예제
##################################################################################

~String()
{
	delete[] mString;
}

String str1{"hello"};

str2 { st1 };

이런식으로 동적할당이 존재하는 멤버를 가진 클래스를 복사를 한다면??
어떤 문제가 발생할까

String str1{"hello"};

str2 { st1 };


str1 클래스가 만들어지면
str1 안에 포인터변수 
mString이 스택에 만들어지고
동적할당이니 Heap에 "Hello\0"의 저장공간을 카르기게 될거다

그럼 이 클래스 객체를 str2로 복사가 이루어질테고

스코프를 벗어나면 소멸자가 불리어 지게 되는데

여기서 문제가 생기게 된다


str1의 mString은 Heap에 "Hello\0"을 가르키게되고
마찬가지로
str2의 mString도 같은 주소값인 "Hello\0"를 가르키게 된다

근데 여기서 스코프를 벗어나면 str2가 먼저 소멸자를 호출하는데
여기서 가르키고 있는 주소값의 "Hello\0"를 지우고 스택에 있는 mString도 지우게 된다

그럼 str1의 소멸자가 불리게 되는데 문제는
str1의 mString은 "Hello\0"이 이미 지워졌기때문에 지워진 포인터에 접근하게된다

그래서 프로그램이 죽는다

이런 문제점이 있다

복사의 개념이
메모리를 많이 잡아먹고 시간도 오래걸리는것도 거슬리지만
치명적인문제
Swallow Copy 와 Deep Copy의 문제를 야기 시킨다

얕은 복사 와 깊은 복사


방금 보여준 이런예제는 얕은 복사가 이뤄진것



str1의 mString이 가르키고있는 주소값의 데이터를 
Heap의 다른공간에 동일한 데이터를 복사하고
str2의 mString이 가르키게 하면 문제가 없다

이런경우 깊은복사를 해서 해결할수도있는데
이럴때 복사생성자를 사용해서 해결하면된다

표현식 예제

String(const String& origin)
{
	mString = new char[origin.동적배열의 길이]; // 새로 동적할당해주고
	for()
	{
		mString[i] = origin.mString[i]; // 대충 복사를 해주는 식을 넣어주면 된다
	}
}

이런식의 복사를 깊은 복사라 한다
복사생성자를 이용

얕은복사는
mString = origin.mString // 요런 너낌 주소값만 넘겨주는 고런 느낌

str1 = st2;
멤버변수는 멤버변수끼리 대입하는거니깐
보통 대입을 하면 얕은 복사


##########################################################################################

!!!!!멤버변수에 포인터변수가 있을경우
얕은 복사와 깊은복사의 개념을 잘 생각해봐야한다

매우중요합니다!!

##########################################################################################


#Realtionship
관계성

1.
is-part=of : 결합

2.
has-a  : 소유/집단화

3.
use-a  :사용/ 연관

4.
is-a   : 특수화 혹은 일반화 
		 상속


##########################################################################################

연습문제


동적으로 문자열을 관리할 수 있는 String 완성해 봅시다.

#생성자

비어 있는 문자열 만들기
			String empty;
총 10글자를 저장할 수 있는 문자열 만들기
			String sized(10);
리터럴로 생성
			String s1("test");
다른 인스턴스로부터 복사
			String s2(s1);


#소멸자

동적 할당한 배열 제거


#연산자

+
->String s3 = s1 + s2;

=	
->s4 = s3;

+=	
->s5 += s1;

[]	
->std::cout << s5[0] << s5[1];

->s5[0] = 'T';

<<	
->std::cout << s3 << std::endl;




*/
