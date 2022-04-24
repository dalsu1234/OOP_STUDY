#include <iostream>
#include "Stack.h"


void Stack::Push(int n)
{
	LinkedList* p = new Stack;
	
	GetLink(*this->mPin,*p,n);
	this->mPin = p;
}

void Stack::Pop()
{
	if (mPin == nullptr)
	{
		return;
	}


	if (CheckEmpty(mPin))
	{
		mPin = LinkSwap(*mPin);
	}
	else
	{
		if (mPin != nullptr)
		{
			mPin = nullptr;
		}
	}
}


void Stack::PrintInfo()
{
	int n{};
	bool isExit = true;
	while (isExit)
	{
		std::cout << "--------------" << std::endl;
		std::cout << "[1] Push " << std::endl;
		std::cout << "[2] Pop " << std::endl;
		std::cout << "[3] Exit " << std::endl;
		std::cout << "--------------" << std::endl;
		std::cin >> n;
		switch (n)
		{
		case 1:
		{
			int num;
			std::cout << "InPut Number" << std::endl;
			std::cout << "--------------" << std::endl;
			std::cin >> num;

			Push(num);
			Print();
			break;
		}
		case 2:
			Pop();
			Print();
			break;
		case 3:
			isExit = false;
			break;
		default:
			break;
		}
		if (!isExit)
		{
			break;
		}
	}
}

void Stack::Print()
{
	std::cout << "--------------" << std::endl;
	if (mPin == nullptr)
	{
		std::cout << "empty" << std::endl;
		std::cout << "--------------" << std::endl;
		return;
	}

	int n{};
	n = GetCount(*this->mPin);

	LinkedList* p{};
	p = mPin;
	
	for (int i = 0; i < n; i++)
	{
		std::cout << GetNum(*p) << std::endl;
		if (CheckEmpty(p))
		{
			p = LinkSwap(*p);
		}
	}

	std::cout << "--------------" << std::endl;
	
}

