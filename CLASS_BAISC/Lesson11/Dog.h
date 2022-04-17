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

	BREED GetBreed() const; // ǰ���� ��ȯ�ؾ��ϴϱ� ��ȯŸ���� BREED 
	void SetBreed(BREED breed);  // ǰ���� �Ű������� �޾ƾ� �ϴϱ� 

	void Roll();
};

// Animail ���Ŭ������ �״�� ����ϸ鼭 �̷������� Ư��ȭ�� ����鵵 ���� ����Ҽ��ִ�
// �̰� �ٷ� ���
