#include <iostream>
#include "Stack.h"

void Stack::Push(int data)
{
	Node* node = new Node;

	node->mData = data;
	node->pNext = pTop;
	pTop = node;
	mCnt++;
}

void Stack::Pop()
{
	if (pTop == nullptr)
	{
		return;
	}
	Node* pTemp = pTop->pNext;

	delete[] pTop;
	pTop = pTemp;
	mCnt--;

}

void Stack::Print()
{
	int s{};
	bool isExit = true;
	while (isExit)
	{
		std::cout << " [1] push " << std::endl;
		std::cout << " [2] pop " << std::endl;
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
			Push(input_n);
			StackPrint();
			break;
		}
		case 2:
			Pop();
			if (pTop == nullptr)
			{
				std::cout << "empty" << std::endl;
				break;
			}
			StackPrint();
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

void Stack::StackPrint() const
{
	Node* pTemp = pTop;

	for (int i = 0; i < mCnt; i++)
	{
		std::cout << pTemp->mData << std::endl;
		pTemp = pTemp->pNext;
	}
}
