#include <iostream>
#include "Queue.h"

void Queue::Enqueue(int num)
{
	Node* node = new Node;
	node->data = num;
	node->pNext = nullptr;

	if (pHead == nullptr)
	{
		pHead = node;
		pCurrent = node;
	}
	else
	{
		pCurrent->pNext = node;
		pCurrent = node;
	}

	mCnt++;
}

void Queue::Dequeue()
{
	Node* temp = pHead->pNext;

	delete pHead;
	pHead = nullptr;

	pHead = temp;
	mCnt--;
	if (pHead == nullptr)
	{
		std::cout << "empty";
		return;
	}
}

void Queue::PrintQueue()
{

	Node* temp = pHead;
	for (int i = 0; i < mCnt; i++)
	{
		std::cout << temp->data << " ";
		temp = temp->pNext;
	}
	std::cout << std::endl;
}

void Queue::Print()
{
	int s{};
	bool isExit = true;
	while (isExit)
	{
		std::cout << " [1] Enqueue " << std::endl;
		std::cout << " [2] Dequeue " << std::endl;
		std::cout << " [3] exit " << std::endl;
		std::cout << " ============ " << std::endl;
		std::cin >> s;

		switch (s)
		{
		case 1:
		{
			int input_n{};
			std::cout << "³ÖÀ» °ª : ";
			std::cin >> input_n;
			Enqueue(input_n);
			PrintQueue();
			break;
		}
		case 2:
			if (pHead == nullptr)
			{
				std::cout << "empty" << std::endl;
				break;
			}
			Dequeue();
			PrintQueue();
			break;
		case 3:
			isExit = false;
			break;
		default:
			break;
		}
		if (isExit == false)
		{
			break;
		}
	}
}
