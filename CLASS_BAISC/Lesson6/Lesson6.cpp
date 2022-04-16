/*
const
#Ŭ���� ���


����>>
#################################################################################
class MyClass
{

public:
	int mValue1;
	int mValue2;

	MyClass()
	{
	}
	MyClass(int v1, int v2) : mValue1{ v1 }, mValue2{ v2 }
	{
	}

	void SetValue1(int x)
	{
		mValue1 = x;
	}

	void Print()
	{
		std::cout << mValue1 << ", " << mValue2 << std::endl;
	}

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}


int main()
{
	MyClass c1; // �⺻ �����ڷ� ������� c1 ��ü

	MyClass c2(2, 2); // ��Ʈ�� �Ű����� 2���� ����ϴ� �����ڷ� ������� c2��ü

	MyClass c3{ 3,3 }; // ������ �ʱ�ȭ�� ����ؼ� �ʱ�ȭ�� c3

	c1.Print(); 
	c2.Print();
	c3.Print(); // ���� ����� 1,1   2,2   3,3
}

######################################################################################

����� ������ ��ü

int main()
{
	const MyClass c1;

	const MyClass c2(2, 2); 

	const MyClass c3{ 3,3 }; 

	c1.Print(); // ���⼭ ������ ����
	c2.Print(); // ������?
	c3.Print(); //
}

#������ ������ ����

  �����ü�� 
  ��ü�� ������ �ٲ�� �ȵȴٶ�� ��
  
  �ʱ�ȭ�� �����ϴ�
  �ʱ�ȭ ���Ŀ��� ���� �ٲܼ� ����
  
  ������ Print() �Լ��ȿ��� ���� �����Ҽ��ִ� ���ɼ��� ����
  ������ �ڵ带 Print()�ȿ� ���� �����ϴ� �ڵ带 �ۼ��Ѵٸ�??
  
  �׷��� ���� ������ ������ִ� ������ �ֱ⶧����
  �����Ͽ��� ������ ����°�
  
#�ذ�å

>> Print() const;
  ��� ��� �Լ��� ����ϸ�ȴ�.
  
  �� �ǹ̴� Print() �Լ� �ȿ� ���� ���������ʴ´ٴ� ������ ���ش�
  
  ����� ��ü�� ����Ѵٰ� �ص�
  �Ǵ� Private�� ��ȣ�Ѵٰ� �ص�
  Ŭ�����ȿ��� �Լ��� �������� �� ������� �����ϰ� �����Ҽ��ֱ⶧����
  �̷����� ����Լ��� ����Ͽ��� �׾ȿ� ������������ ���ϵ���
  �ۼ��ϴ°��� �߿��ϴ�


-------------------------------------------------------------------------------


static
#����

void DoSomething()
{
	static int x = 1;
}

����ƽ ������ Ư¡

-�ѹ� �����Ǹ� �������� ����� ���α׷� ���ᰡ �ɶ����� �����Ѵ�.

����>>
##################################################################

class MyClass
{
public:
	static int mValue;
};

int main()
{
	MyClass c1;  // Ŭ������ ��ó�� �ν��Ͻ�ȭ �ؾ��� ���������
	c.mValue; // ����// ���ǵ������� ��� // �ֱ׷���?

}

######################################################################

static ���

Ŭ���� ����� static�� ���� �ٸ� �ǹ̸� ������

�ѹ� �����Ǵ°� �Ϲ����� static�� ������

�ѹ� ��������� ������ �����Ϸ���
�ν��Ͻ����� �Ǹ� �ȵȴ�
������?? 

#���� ��� ����
	�ν��Ͻ� ������ �ƴ� , Ŭ���� ����
	��������� Ŭ���� ������ �ȴ�

	�׷��� �ٸ��̸����� Ŭ���� ������� �θ���

	�������� �������δ�
	�ν��Ͻ������� �ȴٸ� ������������� �� �ν��Ͻ��� ����
	�����ϰų� �Ҹ��Ҽ����ֱ⶧���� �׷��Ű��� // ������/�Ҹ���


	������ ������ �����ϴ°��� ������ �ƴ� ����
	Ŭ������ �׷��� �ν��Ͻ�ȭ �����ʴ��̻� �����ϴ°��� �ƴϴ�


######################################################################
class MyClass
{
public:
	static int mValue; // << ����  �� ���ǰ� �ʿ��ϴ�
};

int MyClass::mValue = 0;  // << ����    // �̷�������

######################################################################

  ���� ��� ������ �ν��Ͻ��� ����� ����� �Ѵ�
  �׷��� Ŭ������ �����Ǿ�� �ϴµ�
  Ŭ������ ���Ƿ� ���������ʴ´�
  �׷��� ���� ��� ������ �̷������� ���Ǹ� �ؾ��Ѵ�



# ���� ��� ǥ��

######################################################################

class MyClass
{
public:
	static int mValue; 
};

int MyClass::mValue = 0;

int main()
{
	MyClass c1;

	MyClass c2; 
	
	
	// ���� ���� ǥ����� �ƴϴ�
	//c1.mValue = 1;
	//c1.mValue = 10;

	//std::cout << c1.mValue << std::endl;
	//std::cout << c2.mValue << std::endl;
	//�������̳� ��뿡�� ������ ������

	// �ǹٸ� ǥ���

	MyClass::mValue = 1; // ���������� Ŭ������ �����ϴ� ������
	// �̷������� ��Ȯ�ϰ� �ۼ��Ѵ�
	
	std::cout << MyClass::mValue << std::endl;

}
######################################################################

// ���� Ŭ���� �ȿ�
static int mValue; �� 
static int mValue = 0; ������ �����Ѵٰ� �ص� ����� �ƴ��̻� �Ұ����ϴ�
// �����Ͽ���


######################################################################
class MyClass
{
public:
	static int mValue;
};

int MyClass::mValue = 0;


######################################################################
// �ݵ�� ��ó�� �и��ؼ� �����ϰ� �����ؾ��Ѵ�


���� 1
######################################################################

class Counter
{
public:
	static int sCount;

	void Count()
	{
		std::cout << sCount << std::endl;
		sCoutn++;
	}

};

int Counter::sCount { 1 };

######################################################################

���� 2

class MyClass
{
public:
	static int sCount;

	MyClass()
	{
		sCount++;
	}

	~MyClass()
	{
		sCount--;
	}

}

int MyClass::sCount { 0 };

int main()
{
	std::coout << MyClass::sCount << std::endl;
}

MyClass�� ��� ��µȰ��� �˼��ִ� ��?

int main()
{
	MyClass c1;
	
	{
		for(int i = 0; i < 5; i++)
		{
			MyClass c2;
		} // ���⼭ c2 �Ҹ��ڰ� ȣ��
		
		MyClass c3;
	}// ���⼭ c3 �Ҹ��ڰ� ȣ��

	std:cout << MyClass::sCount << std::endl;

}// ���⼭ c1 �Ҹ��� ȣ��

�׷��� ��°��� 1 �̵ȴ� 

######################################################################


---------------------------------------------------------------------------------------


# ���� ��� �Լ�
static member function (class function)

���� ��� ������ ���� 
�ν��Ͻ��� �ҼӵȰ��� �ƴ϶�
Ŭ������ ���Ѵ�

���� 1
######################################################################

class MyClass
{
public:
	static int sCount;

	void Order()
	{
		sCount++;
	}

};

int MyClass::sCount { 0 };

int main()
{
	MyClass c1, c2 , c3;

	c1.Order();
	c2.Order();
	c3.Order();  // static �Լ��� ����� �̷������� ������ �����ʿ䰡 ����

}


class MyClass
{
public:
	static int sCount;

	static void Order() // ���� ��� �Լ�
	{
		sCount++;
	}

};

int MyClass::sCount { 0 };

int main()
{
	MyClass c1, c2 , c3;

	MyClass::Order();
	MyClass::Order();
	MyClass::Order(); // �̷������� ��� ����

	std::cout << MyClass::sCount << std::endl;

	//�ν��Ͻ��� ��� �Ǵ� ����̾���
}

######################################################################

----------------------------------------------------------------------


# friend
	
	A�� B�� ģ���� �����ϸ� B�� A�� ��� ����� �˼��ִ�
	������ A�� B�� �𸥴�

	����Ʋ�̶�� �����ϸ� �ɵ�?

	�������� ������ ����� �����ϴ°�


���� 1
######################################################################


class Sword
{
private:
	int mDamage;

public:
	Sword(int dmg) : mDamage {dmg}
	{

	}
	
};

class Warrior
{
public:
	void Attack(Sword& sword);
	{
		std::cout << "Į�� �ֵѷ�" << sword.mDamge << std::endl; 
		// ������ ���� //�ֳĸ� sword.mDamge�� private �̴ϱ�
		// �ذ�����? �Ϲ������� getter�� ����ϸ� �ȴ�
		// ������ friend�� ����Ѵٸ�?

	}

};

int main()
{
	Sword shortSword(10);
	Warrior player1;

	player.Attack(shorSword);
}



#
friend ��� ����
##############################################################


class Sword
{

	friend class Warrior;  // �̷������� ���  // ģ�� Ŭ���� ###
	
	friend void UpgradeSword(Sword& sword);    // ģ�� �Լ�   ###

private:
	int mDamage;

public:
	Sword(int dmg) : mDamage {dmg}
	{

	}

};

class Warrior
{
public:
	void Attack(Sword& sword);
	{
		std::cout << "Į�� �ֵѷ�" << sword.mDamge << std::endl;
		//���� �����带 ����  �ϸ� private�� �����Ҽ��ִ�

	}

};

void UpgradeSword(Sword& sword) 
{
	sword.mDamage *= 2;
	std::cout << "��ȭ ���� : " << sword.mDamge <<std::endl;
}

int main()
{
	Sword shortSword(10);
	Warrior player1;

	UpgradeSword(shortSword);

	player.Attack(shorSword);
}


######################################################################

ģ�� Ŭ������ ģ�� �Լ� �ΰ����� ����
ģ�� ������ �����Ҽ��� ����

friend void UpgradeSword(Sword& sword)
{
	sword.mDamage *= 2;
	std::cout << "��ȭ ���� : " << sword.mDamge <<std::endl;
}

// �̷������� ����� ���Ƿ� ���� ����Ҽ��� �ִ�
// Ŭ���� �ȿ� �ִٰ� �ؼ� �̰� Ŭ�������� �ƴϴ�
// �����Լ��� ������ �̰� �����Լ��̴�
// Ŭ������ ���� �������
######################################################################

- ģ�� Ŭ����
- ģ�� �Լ� ������ �ôٸ�

	ģ�� ����Լ��� �����Ѵ�

ģ�� ����Լ� ����>>
######################################################################

# ģ�� ��� �Լ�

class Sword
{

friend void Warrior::Attack(Sword& sword); // ģ�� ��� �Լ� ���� ##
// ������ �������� �ȵȴ�
// ������?? Warrio��� Ŭ������ ������ �Ʒ��ʿ� �־
// ���� ����
// �׷��ٸ� Warrior Ŭ������  ���� �����Ѵٰ� �����Ѱ� �ƴϴ�
// ������ �Ű������� Sword& Ŭ������ �ʿ�� �ϴµ� �Ʒ��ʿ� �־
// �Ұ����ϴ�
// # �ذ��?
// ����� ���Ǹ� �и��ؼ� ����Ѵ�
// ���� ������ �ϰ� ���Ǹ� �Ʒ��� �ۼ��ϸ� �ȴ�


private:
	int mDamage;

public:
	Sword(int dmg) : mDamage {dmg}
	{

	}

};

class Warrior
{
public:
	void Attack(Sword& sword);
	{
		std::cout << "Į�� �ֵѷ�" << sword.mDamge << std::endl;
		//���� �����带 ����  �ϸ� private�� �����Ҽ��ִ�

	}

};

void UpgradeSword(Sword& sword)
{
	sword.mDamage *= 2;
	std::cout << "��ȭ ���� : " << sword.mDamge <<std::endl;
}

int main()
{
	Sword shortSword(10);
	Warrior player1;

	UpgradeSword(shortSword);

	player.Attack(shorSword);
}

######################################################################

# �ذ��



class Warrior
{

public:
	void Attack(Sword& sword);

};


class Sword
{


private:
	int mDamage;

public:
	Sword(int dmg) : mDamage {dmg}
	{

	}

friend void Warrior::Attack(Sword& sword); // ���⼭ ������ �ϰ� ##

};


void Warrior::Attack(Sword& sword)  // ���⼭ ���Ǹ� �Ѵ� ##
{
	std::cout << "Į�� �ֵѷ�" << sword.mDamge << std::endl;
}

######################################################################

������ friend �� �� ��������ʴ´�

	������ ��ư�
	����� �����ϴ� (����� ����)
	ĸ��ȭ ��Ģ���� �����

������ �����ϰ� �����ִ°�찡 �Ѱ��� �ִ�

�ٷ� Operator Overloading

������ �����ε��� �ִ�

*/