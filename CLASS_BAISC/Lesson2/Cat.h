#pragma once
class Cat
{
private:
	int mAge;

	//��� ��� ����
	const int LEG_COUNT = 4;


public:
	
	void Meow();
	
	
	//��� ��� �Լ�
	//const void Meow(); �̰� ��ȯ���� ������ ���̱⶧���� ����Լ��� ������ ���� �ƴϴ�
	
	int GetAge() const;
	// ��� ����Լ��� �ǹٸ�ǥ��
	// �� ��� ����Լ��� �ν��Ͻ��� ���
	// �Ϲ������� �������Լ��� getter�Լ����� ���� ����Ѵ�
};

