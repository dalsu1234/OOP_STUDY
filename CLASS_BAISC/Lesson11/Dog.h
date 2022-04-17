#pragma once
#include "Animal.h"
class Dog : public Animal
{
public:
	enum BREED
	{
		BEAGLE, DOBERMAN, BERNARD, CHIHUAHUA, HUSKY
	};

private:
	BREED mBreed;

public:
	Dog();
	~Dog();

	BREED GetBreed() const; // 품종을 반환해야하니깐 반환타입이 BREED 
	void SetBreed(BREED breed);  // 품종을 매개변수로 받아야 하니깐 

	void Roll();
};

// Animail 기반클래스를 그대로 사용하면서 이런식으로 특수화한 멤버들도 따로 사용할수있다
// 이게 바로 상속
