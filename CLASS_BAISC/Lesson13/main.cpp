#include <iostream>
#include "Warrior.h"
int main()
{

	Character* pHero = new Warrior;

	pHero->Attack();

	//pHero->DoubleSlash(); 
	// ������ ����
	// ���� Attack()�� �������� Attack()�� �Ǵ� ������
	// ���Ŭ������ Attack�Լ��� �����Լ��� ����������
	// DoubleSlash()�� ������� �����ϴ� �Լ��� 
	// ���Ŭ�������� ���⶧����
	// ���⼭ pHero�� Character Ÿ���̱⶧���� 
	
	// �׷��� DoubleSlach�� Warrior�� ������ Ÿ������ ����ȯ���ָ��ذ�
	
	
	((Warrior*)pHero)->DoubleSlash();
	
	// ����� ����ȯ
	//(Warrior*)pHero->DoubleSlash()
	// �̷��� ���� pHero�� DoubleSlash�� 
	//��ȯŸ���� Warrior�� ������ Ÿ������ �ٲ��شٴ� �ǹ�
	// �� �����ȵǴ� ǥ�����ΰŴ�
	// void ��ȯ���� Warrior*�δ� �����ȵǴ°��ܿ�

	// ������ �����Ҹ� ������ �ִ�
	// �������� pHero = new ����; �̶�� �����Ѵٸ�??
	// ������ ����� �����ִ�

	float x = 10.5f;
	int y = static_cast<int>(x);   //����ĳ������ ��

	((Warrior*)pHero)->DoubleSlash();
	// ����ĳ�������� �ٲ㺸��
	dynamic_cast<Warrior*>(pHero)->DoubleSlash();
	// �̷��� �ٲܼ��������� �̰� �� �İ� ���� ������ ǥ���� �ƴϴ�
	
	//������ǥ���� �ϰ�ʹٸ�?
	
	Warrior* pWarrior = dynamic_cast<Warrior*>(pHero);
	if (pWarrior == nullptr)
	{
		std::cout << "Error" << std::endl;
	}
	else
	{
		pWarrior->DoubleSlash();
	}
	//�̷��� ǥ���ϴ°� �ſ� �����ϴ�
	delete pHero;
}