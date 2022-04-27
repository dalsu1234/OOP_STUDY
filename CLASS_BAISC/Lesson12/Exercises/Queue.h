#pragma once
#include "LinkedList.h"
class Queue : public LinkedList
{
	LinkedList* mHead;
	LinkedList* mTail;
public:
	Queue() : mHead{ nullptr }, mTail{ nullptr } {};
	Queue(int n) : LinkedList(n), mHead{ nullptr }, mTail{nullptr}{};
	~Queue();
	void AddNode(int num);
	void RemoveNode();
	void Info();
	void Print();

};

