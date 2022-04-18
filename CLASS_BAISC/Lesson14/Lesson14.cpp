/*

#namespace


namespace 이름 공간에 대한 명칭
{

};
이름이 겹치는걸 막을수있다

class Warrior
{
public:
	void Print();
};

void Print()
{
	// 플레이어의 정보를 출력하는 내용
}

class HUD
{

};

void Print()
{
	//UI 출력을 위한 내용
}
###############################################################
이렇게 이름이 겹쳐지는 경우가 생긴다

이럴때
namespace로 묶어줄수있다



예제>>
#################################################################

namespace Character  //이렇게 묶으면 Character라는 이름공간안에
{					 // '하위 개념'으로 들어가진다
	class Warrior
	{
	public:
		void Print();
	};

	void Print()
	{
		// 플레이어의 정보를 출력하는 내용
	}

}

namespace GUI
{

	class HUD
	{

	};

	void Print()
	{
		//UI 출력을 위한 내용
	}
}


이렇게 나눠서 사용하면 편하다
각각 Character와 HUD라는 이름공간으로 각각 묶어놓는다
이름공간의 하위개념으로 클래스나 멤버함수들이 들어간다

int main()
{
	Character::Warrior player;   // 이렇게 이름공간(namespace) 안에 있다라는걸 알려줘야한다
	player.Print();

	GUI::HUD hud;   // 이것도 GUI안의 공간에 HUD가 있는 형태
	GUI::Print();

}

###########################################################

전역 함수들은
눈에 보이지 않지만

::Print(); 이렇게 해석할수있다


###########################################################

만약 이름공간:: 을 일일히 써주기 불편하다면

using namespce 이름공간명; 을 선언해서 쓰면

GUI::Print(); 이렇게 쓸필요없이
Print(); 이름공간을 지정안해도 이렇게 쓸수있다

하지만 주의점
헤더파일에서

Character::
전역함수::
의 각각 print() 함수가 있다고 할때
using namespace Character; 를 쓴다면

전역함수의 Print함수를 불러야할지
Character 이름공간에 있는 Print함수를 불러야할지
누구를 지정해야할지 몰라서 컴파일 오류가 남

그래서
Charcter안에 있는 print함수는
Character::Print();

전역 함수에 있는 프린트함수는
::Print(); 이렇게 호출해야한다

#########################################################

using namespace 주의사항

	- cpp 파일에서만 사용!!
	- 헤더파일에서는 절대사용금지
		(헤더파일의 특징때문) include때문에 매우 위험
#########################################################


# template


void Sort(int input[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if (input[i] > input[j])
			{
				int temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}
}

int main()
{
	int array[]{ 5,3,2,4,1 };

	Sort(array, 5);

	for (int i = 0; i < 5; ++i)
	{
		std::cout << array[i] << std::endl;
	}
}

이런 코드가 있다
이코드에는 문제가 있다

	int array[]{ 5,3,2,4,1 };
	이 배열을
	double array[]{ 5,3,2,4,1 };
	double 배열의 타입으로 정렬할수없다
	이 배열을 정렬 하려면 또
	double 의 매개변수를 받는 오버로딩함수를 만들어야할거다

	하지만 이러면 너무 번거롭고 너저분해진다

	물론 함수의 매개변수를 void* input 으로 바꾼다면
	더블이라던지 정수형이라던지 다 가능해지지만

	하지만 이것역시 문제점이 있다
	역참조가 불가능하다
	왜냐
	보이드 포인터는 들어오는 값이 무슨 타입인지 모르기때문에
	역참조를 못한다
	역참조를 하려면 타입을 알아야 하니깐

	스태틱 캐스트로 변환하는 방법으로 해결할수있는 방법이 있지만
	역시나 번거로운건 사실

	그래도 보이드 포인터는 좋은기능이니깐 잘 외워두자


	여하튼 이럴때 사용하기 좋은게 template

#########################################################################

# template

	- 타입을 일반화로 선언 어떤타입이 와도 처리할수있게된다

	- 프로그래머가 원하는 타입으로 특수화 시켜서 사용

	- 보이드 포인터와 다를게 없지만 템플릿은 컴파일러가 자동으로 해준다

	즉 타입을 일반화 하고 원하는 타입으로 특수화 시키면
	컴파일이 알아서 해주는 좋은기능

#일반화

	template <일반화 타입 이름 1, 일반화 타입 이름 2,...... >

	template <typename T1, typename T2>  // 타입이 있다라고만 가정해주면 된다
	template <class T1 , class T2>       // 클래스 타입 예시

	옛날에는 일반 타입과 클래스 타입을 구분지어서 사용했지만

	요즘은 모든타입들을

	template <typename T1, typename T2> 이렇게 사용한다

	예제
	###############################

	template <typename T>
	void DoSomething(int x)
	{
	}
	이렇게 선언하면 이제부터
	void DoSomething(T x)
	이렇게 선언할수있다
	그럼 이제 어떤 타입이 와도 사용할수있고
-------------------------------------------------------------

#특수화

	사용하고자 하는 타입을 <타입>안에 추가

	예제
	################################

	DoSomethig<int>(1);
	이렇게 특수화에서 타입을 명시해주면 된다
	################################

일반화는  템플릿에 선언이고
특수화는  템플릿을 사용 하는건가..

-----------------------------------------------------------------------

템플릿 예제>>
#######################################################################

template <typename T>
T Function (T arg1, T arg2)
{
	T result = arg1 + arg2;

	return result;
}

int main()
{
	int x{1}, y{2};

	Function<float>(x,y);
	Function<int>(x,y);
	Function<double>(x,y);
	이렇게 타입의 제한없음 자유롭게 사용이 가능하다

}


#######################################################################

template의 핵심은
컴파일러가 해준다는게 핵심이다

일반화를 한 코드를 따로 저장해두었다가
특수화를 만나면 명시한 타입으로
일반화에서 저장한 코드를 일일히 명시한 타입으로
자동적으로 컴파일이 작성해주는 느낌일려나

여하튼 특수화를 여러개 할수록 안보이는 코드들이 그만큼 늘어난다

자동으로 코드가 생성


#######################################################################



예제2>>
#######################################################################
template<typename T>
void Sort(T input[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if (input[i] > input[j])
			{
				T temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}
}

int main()
{
	int array[]{ 5,3,2,4,1 };

	Sort<float>(array, 5);

	for (int i = 0; i < 5; ++i)
	{
		std::cout << array[i] << std::endl;
	}
}

#######################################################################


int array[]{ 5,3,2,4,1 };

	Sort<float>(array, 5);


	위에 특수화를

	Sort(array, 5);
	이렇게 생략할수도 있다
	이유는 매개변수로 들어가는 타입이 무엇인지 컴파일러가 추론할수있으니
	이렇게 생략할수도있다

#######################################################################


클래스에서 template사용


#######################################################################


class LinkedList
{
	int* m_pHead = nullptr;
	int* m_pTail = nullptr;
};

template<typename T>
class LinkedList
{
	T* m_pHead = nullptr;
	T* m_pTail = nullptr;
};


LinkedListe<Monster> monsters;

LinkedListe<Player> monsters;

LinkedListe<int> monsters;  // 이렇게 다양하게 쓸수있게된다

class MyClass
{
public:
	template<typename T>
	void DoSomething(T x)
};// 클래스나 멤버함수모두 사용 가능하다


#######################################################################

하지만 클래스에선 단점이 존재한다
컴파일러가 자동으로 해준다는게 문제가 될수있다


예제>>
#######################################################################

// 헤더파일에서의 선언
template <typename T>
class Game
{
	T mValue;
public:
	void Funtion(T arg);

};

// cpp에서의 정의
#include "Game.h"

template<typename T> // 여기서 한번더 동일하게 템플릿해줘야한다
void Game::Funtion(T arg) // 컴파일러 오류
{

}
컴파일 오류 이유는?

함수의 정의란 무엇인가?
함수의 정의를 하려면 무엇이 필요하냐
멤버함수같은 경우는 누구의 것이냐가 중요하다

템플릿멤버함수를 정의할때는
그 클래스가 어떤 타입으로 특수화되었는지 알아야한다
즉

void Game<T>::Funtion(T arg)

이렇게 바뀌어야 한다 명시적으로 템플릿타입을 알려줘야한다

Game이라는 클래스는 더이상 그냥 클래스가 아니라
템플릿이라는 틀안에 들어가있는 모양새라고 이해하면 되나


#사용법


int main()
{
	Game<int> c1;

	c1.Function(10);  // 여기서 컴파일 오류
	이유는??
	템플릿은 기본적으로 컴파일이 알아서해준다
	int로 특스화 하게 되면
	새로 int형으로 변경해서 코드를 추가되는데
	이렇게 되면 무슨일이 벌어지느냐

	int버전의 함수의 정의가 누락되어있게 된다
	먼소리냐 컴파일러는
	클래스의 선언은 헤더파일 정의는 cpp에 있는데
	자동으로 코드를 만들어주는데

	자동으로 만들어주는 장소는 선언의 위치에 만들어준다
	하지만 정의가 다른 파일에 가있는데
	이러면 오류가 생길수밖에
	cpp의 정의는 즉 아무 의미가 없다

	그래서 해결법은


}
클래스에서 템플릿은 반드시
!! 정의는 반드시 선언에 함꼐 있어야한다
헤더파일안에 다 몰아주던가
cpp파일안에 다 몰아주던가

이게 유일한 단점이다



#############################################################

template <typename T>
class Game
{
	T mValue;
public:
	void Function(T arg);
};


template<typename T>  // 여기서 또 정의해줘야함
void Game<T>::Function(T arg)
{
	T result = arg + arg;
	mValue = result;
}

이렇게 헤더파일에 이쁘게 모아주면 된다


이게 보기가 싫다면

선언은 헤더파일에
정의는 .cpp가 아닌 .hpp 파일에 만들어주면 해결된다




*/

