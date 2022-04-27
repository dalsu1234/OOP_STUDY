#include "Stack.h"
#include "Stack.h"
#include <iostream>

Stack::~Stack()
{
}

void Stack::AddNode(int num)
{
	LinkedList* newNode = new Stack(num);

	this->SetLink(*this, *newNode);
	this->mTop = newNode;
	GetCount(*this);
}

void Stack::RemoveNode()
{
	if (mLink == nullptr)
	{
		return;
	}
	mTop = LinkPoint(*mLink);
	mLink = mTop;
	mCount--;

}

void Stack::Info()
{
	int n{};
	bool isExit = true;
	while (isExit)
	{
		std::cout << "[1] Input Stack " << std::endl;
		std::cout << "[2] Remove Stack " << std::endl;
		std::cout << "[3] EXIT " << std::endl;
		std::cin >> n;
		switch (n)
		{
		case 1:
		{
			int data{};
			std::cout << "Input Number" << std::endl;
			std::cout << "  >> ";
			std::cin >> data;
			std::cout << "-------------" << std::endl;
			AddNode(data);
			Print();
			break;
		}
		case 2:
			RemoveNode();
			Print();
			break;
		case 3:
			isExit = false;
			std::cout << "종료합니다." << std::endl;
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
	std::cout << "----Stack----" << std::endl;
	if (mLink == nullptr)
	{
		std::cout << "EMPTY" << std::endl;
		std::cout << "-------------" << std::endl;
		return;
	}
	for (int i = 0; i < mCount; i++)
	{

		std::cout << GetData(*mLink) << std::endl;
		NewLink(*this);
	}
	std::cout << "-------------" << std::endl;
	SwapLinkPoint(*mTop, *this);

}
