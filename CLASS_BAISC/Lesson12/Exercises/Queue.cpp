#include <iostream>
#include "Queue.h"

void Queue::AddNode(int num)
{
	LinkedList* newNode = new Queue(num);

	if (mCount == 0)
	{
		mCount = 0;
		mHead = newNode;
		mTail = newNode;
		SetLink(*mHead, *newNode);
		GetCount(*this);
	}
	else
	{
		SetLink(*mTail, *newNode);
		mTail = newNode;
		GetCount(*this);
	}
}

void Queue::RemoveNode()
{
	if (mCount < 0 || mHead == nullptr)
	{
		mCount = 0;
		
		return;
	}
	mLink = LinkPoint(*mHead);

	mHead = LinkPoint(*this);

	mCount--;
}

void Queue::Info()
{
	int n{};
	bool isExit = true;
	while (isExit)
	{
		std::cout << "[1] Input Queue" << std::endl;
		std::cout << "[2] Remove Queue" << std::endl;
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

void Queue::Print()
{
	mLink = mHead;
	std::cout << "----Queue----" << std::endl;
	if (mCount <= 0)
	{
		mCount = 0;

		std::cout << "EMPTY" << std::endl;
		std::cout << "-------------" << std::endl;
		return;
	}
	for (int i = 0; i < mCount; i++)
	{
		std::cout << GetData(*mLink) << " ";

		NewLink(*this);
	}
	std::cout << std::endl;
	std::cout << "-------------" << std::endl;

}


