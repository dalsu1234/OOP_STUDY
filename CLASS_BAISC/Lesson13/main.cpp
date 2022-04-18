#include <iostream>
#include "Warrior.h"
int main()
{

	Character* pHero = new Warrior;

	pHero->Attack();

	//pHero->DoubleSlash(); 
	// 컴파일 오류
	// 위에 Attack()이 워리어의 Attack()이 되는 이유는
	// 기반클래스의 Attack함수가 가상함수로 선언했지만
	// DoubleSlash()는 워리어에만 존재하는 함수로 
	// 기반클래스에는 없기때문에
	// 여기서 pHero는 Character 타입이기때문에 
	
	// 그래서 DoubleSlach를 Warrior의 포인터 타입으로 형변환해주면해결
	
	
	((Warrior*)pHero)->DoubleSlash();
	
	// 명시적 형변환
	//(Warrior*)pHero->DoubleSlash()
	// 이러면 뜻이 pHero의 DoubleSlash의 
	//반환타입을 Warrior의 포인터 타입으로 바꿔준다는 의미
	// 즉 말도안되는 표현식인거다
	// void 반환값을 Warrior*로는 말도안되는거잔여

	// 하지만 위험요소를 가지고 있다
	// 누군가가 pHero = new 도적; 이라고 수정한다면??
	// 안전한 방법이 따로있다

	float x = 10.5f;
	int y = static_cast<int>(x);   //정적캐스팅의 예

	((Warrior*)pHero)->DoubleSlash();
	// 동적캐스팅으로 바꿔보자
	dynamic_cast<Warrior*>(pHero)->DoubleSlash();
	// 이렇게 바꿀수도있지만 이건 위 식과 같이 안전한 표현이 아니다
	
	//안전한표현을 하고싶다면?
	
	Warrior* pWarrior = dynamic_cast<Warrior*>(pHero);
	if (pWarrior == nullptr)
	{
		std::cout << "Error" << std::endl;
	}
	else
	{
		pWarrior->DoubleSlash();
	}
	//이렇게 표현하는게 매우 안전하다
	delete pHero;
}