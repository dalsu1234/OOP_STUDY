#pragma once
class Queue
{
	struct Node
	{
		Node* pNext{ nullptr };
		int data{};
	};
	Node* pHead;
	Node* pCurrent;
	int mCnt;

public:

	Queue() : pHead{ nullptr }, pCurrent{ nullptr }, mCnt{ 0 }{};
	~Queue()
	{
		pCurrent = nullptr;
	}
	void Enqueue(int num);
	void Dequeue();
	void Print();
	void PrintQueue();
};

