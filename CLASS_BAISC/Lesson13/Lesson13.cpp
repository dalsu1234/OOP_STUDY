/*

Typecast

class Character{};   // ���Ŭ����

class Warrior : public Character{}; // �Ļ�Ŭ����


Character is-a Warrior
ĳ���ʹ� �������      �̸��� �������� �ְ� Ʋ�������ִ� ����

Warrior is-a Character
������� ĳ���ʹ�      �´� ����



up-cast			vs			down-cast

�ڽ� -> �θ�				�θ� -> �ڽ�

�����Ѻ�ȯ					üũ�ؾ��Ѵ�(��Ÿ�Ӷ� üũ�غ��� �˼�����)

�Ͻ�����ȯ					��������ȯ



up-cast����>>
##########################################
Character* pHero = new Warrior();
���⿡�� �̹� �Ͻ��� ����ȯ�� ���ǰ��ִ�

WarriorŸ���� ��������� ���ƿ��ٵ�
������� Warrior�� Character*�� ����ȯ��
�̹� �Ͻ������� ���ǰ��ִ°Ŵ�
�̰� ������ ������ up-cast�� ����
�Ļ�Ŭ�������� ���Ŭ�����δ� �����Ѻ�ȯ�̶�
�Ͻ������� ����� �����Ѱ�!!
##########################################

down-cast����
##########################################
Character* pHero = new Warrior();

��

(Warrior*)pHero �� ����������ȯ

pHero�� ���Ŭ���� Ÿ���̴ϱ�
�Ļ�Ŭ������ ����ȯ �Ϸ��� ������ ���������� ����ȯ�� �ϰ�
��Ÿ�Ӷ� üũ�� �Ѵ�
������ ���� ������ ����� �����ϴµ� �װ�
##########################################


#down - cast�� ����ȯ�� ������ Ÿ��

#############################################

static_cast<��ȯ�� ���ϴ� Ÿ��>( ǥ���� );  

dynamic_cast<��ȯ�� ���ϴ� Ÿ��>( ǥ���� );
	- ��Ÿ�Ӷ� Ÿ�Կ� ���� ������ �߰������� �ʿ��ϴ� : RTTI ��� �Ѵ�

#############################################

static_cast �� ����
�������� ĳ��Ʈ�Ѵ�
�� ������Ÿ������ ĳ��Ʈ �Ѵ�

��Ÿ���� �����Ϸ� ĳ���� �Ѵٶ�� �����ϸ� �ǳ�?


����>>
##############################################
float x = 10.5f;
int y = static_cast<int>(x);

##############################################

##���� ĳ����
������ �ٽ��̾߱�


����>>
##############################################
	
	
	((Warrior*)pHero)->DoubleSlash();
	����ĳ�������� �ٲ㺸��

	dynamic_cast<Warrior*>(pHero)->DoubleSlash();
	�̷��� �ٲܼ��������� �̰� �� �İ� ���� ������ ǥ���� �ƴϴ�

	������ǥ���� �ϰ��ʹٸ�?
	###################################################

	Warrior* pWarrior = dynamic_cast<Warrior*>(pHero);

	if (pWarrior == nullptr)
	{
		std::cout << "Error" << std::endl;
	}
	else
	{
		pWarrior->DoubleSlash();
	}

	###################################################
	�̷��� ǥ���ϴ°� �ſ� �����ϴ�


##############################################

�׿ܿ� ����� ���ִµ�

reinterpret_cast<Ÿ��>(ǥ����);
	- �� �ٲ��ִ� ĳ��Ʈ
	- ������ ���ؼ��Ѵ�
	- ������ ���������ʴ´�

const_cast<Ÿ��>(ǥ����)
	- constŸ���� �����ϰų� �ٽ� �����Ҽ��� �ִ� ĳ����

���� �� �ΰ����� �� �Ⱦ�


#############################################

���ó 

���̳���ĳ��Ʈ
��Ÿ�ӿ� Ÿ���� üũ�Ҽ��ִ� ĳ��Ʈ

� Ÿ������ ��Ȯ���ϰų�
���� �������� ��ȯ�� �ʿ��ϴٸ� ���̳���ĳ��Ʈ�� ����Ѵ�

��Ӱ� ���õ� �������� �����͸� ���� ��
üũ�� �ؼ� ���캸�� ���������� ����ȯ�� �Ҷ�


OOP�� ��������
������ �Ÿ������ ��Ÿ�Ӷ� �˼������ϱ�
###############################################

#�߻�Ŭ����

#���������Լ�

���Ŭ�������� �����Լ����� ���� �ʿ��ϰ� 
���Ǵ� �ʿ������ʴ°�찡 �ִ�

�׷����� ���Ŭ���� ������Ͽ���

virtual <Ÿ��> <�Լ���()> {} = 0;

�̷������� ���� ���ټ��ִ�

�̰� ���������Լ�

��ü�� ���� �Լ���

�׳� virtual�� ���ٸ� ��ü�� ���������� �̷������� ���ٸ�
��ü�� ���� �Լ��� ����


������ �̴�� ���ٸ� �߻�Ŭ������ �ν��Ͻ�ȭ �Ҽ����� ��� ������ ������ �����

#############################################################################
#�߻�Ŭ����

	- ������ ���������ʴ� �Լ��� �־���Ѵ�
	>> ���������Լ��� ���� Ŭ������ �߻�Ŭ������ �Ѵ�

	- �ν��Ͻ�ȭ�� �Ұ����ϴ�

	- ��� Ŭ�����θ� ���ɼ��ִ�

	- �Ļ� Ŭ�������� ��� ���� �����Լ��� ������(�������̵�) �ؾ���




����
##########################################################################


class Character
{
public:
	virtual void Attack() cosnt = 0;
	virtual void Dead() const = 0; // �����Լ���
}

class Warrior : public Character
{
public:
	void Attack() override;
	void Dead() override;      // �̷��� �Ļ�Ŭ�������� ������ �������
}

���Ŭ������ �����Լ����� �������� 
�Ļ�Ŭ�������� ������ ������Ѵ�


##########################################################################

#interface
	��� ����Լ��� ���� �����Լ��θ� �̷��� �߻�Ŭ����

	�߻�Ŭ������ �Ѱ��̻��� �����Լ��� �־ �߻�Ŭ������������
	�������̽�ư ��� ����Լ��� �����Լ����ؾ��Ѵ�

##########################################################################

---------------------------------------------------------------------------


##����Լ��� ������

int Sigma(int (*f)(intx),int m, int n)
{
	int sum{};
	for(int i = m; i <= n; ++i)
	{
		// ���� ����	
	}
}

int FuncA(int x)
{
	return x;
}

int FuncB(int x)
{
	return x*x;
}
int main()
{
	Sigma(Func,3,3);
	// �� �̷������� ����ϰԲ� �Ҽ��ְ�
}

int (*f)(intx) // ����Լ�




#�Լ�������

int (*f)(int x)

using f = int (*)(int x);


# ����Լ��� ������

######################################################
����

class MyFunction
{
public:
	int NormalFunc(int x)
	{
		return x;
	}

	int SquareFunc(int x)
	{
		return x*x;
	}
};

using FunPtr1 = int (*) (int);				// �Լ�������
using FunPtr2 = int (MyFunction::*) (int);	// ����Լ��� ������

int Sigma(FunPtr2 f, int m , int n)
{
	int sum{};
	for()
	{
		sum += f(i);
	}
	return sum;
}

int main()
{
	std::cout << Sigma(MyFunction::NomalFunc, 1, 10)<< std::endl;
	std::cout << Sigma(MyFunction::SquareFunc, 1, 10)<< std::endl; 
}


�⺻������ ����Լ����� �ν��Ͻ��� ������ ����� �Ұ����ϴ�
�׷��� �׳� ����Լ����� �Լ������ͷ� ������
�����Ҽ��ִ� ����� static���� ����Լ����� �����ϸ�ȴ�

static���� �����ϸ� �׶����ʹ� ����Լ����� �ν��Ͻ����� �ƴ�
Ŭ������ ���� �Ǳ⶧���� �����ϴ�

������ ������ ����
Ŭ�����ȿ� �ִ� ����������� ����Ҽ�������
Ŭ�������̶� ��� ��������� ���ٿ� ������ ����


�׷� �ذ�å



using FunPtr2 = int (MyFunction::*) (int);	// ����Լ��� �������� ǥ����


int Sigma(MyFunction& instance, FunPtr2 f, int m , int n)
{
	int sum{};
	for()
	{
		sum += (instane.*f)(i); // f��� �Լ������͸� ������
	}

	//(instane.*f)(i) ��ǥ������
	�ν��Ͻ��� �ִ� ����Լ������Ϳ� ����
	�׸��� �Ű����� ������ �Լ��� �������ؾ��ϱ⶧����
	*f�� �ϴµ�
	�׳� ��ȣ ���� ����Ѵٸ� �ǹ̰� �޶����⶧����
	
	(intstanc.*f)(i); �� ����ϸ�ȴ�
	�ν��Ͻ��ȿ� �ִ� �Լ������͸� ������

	
	return sum;
}
int main
{
	MyFunction mf;
	
	std::cout << Sigma(mf, &MyFunction::NomalFunc, 1, 10)<< std::endl;
	std::cout << Sigma(mf, &MyFunction::SquareFunc, 1, 10)<< std::endl;
	// �ϴ� �ν��Ͻ��� �ʿ��ϱ⶧���� Sigma�Լ��� �Ű�������
	�ν��Ͻ��� �Ű������� ����Ѵ�
	MyFunction::SquareFunc �̷��� ����ϸ� Ŭ�����Լ��� �����Ѵٴ� �ǹ��̱�
	������ ������ ������ �����

	&MyFunction::NomalFunc �̷��� ����� �Լ������Ϳ� �����Ѵٴ� �ǹ̰� �ȴ�	
}

��... ��ƴ�

##########################################################################


����


		�Լ�������(��������Լ�)		vs		����Լ��� ������
		
ǥ����	ret-type (*)(param-lis)					ret-type (class-name::*)(param-lis)

����	uisng fptr = int (*)(int x)				uing fptr = int (MyClass::*)(int x)

���	fptr(3)									(instance.*fptr)(3);


�������̸� �ݵ�� �ν��Ͻ��� �ʿ��ϴ�

##########################################################################

-----------------------------------------------------------------------------





*/