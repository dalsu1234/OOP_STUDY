#include "LinkedList.h"
#pragma once

class Stack : public LinkedList
{
	LinkedList* mTop;
public:
	Stack() : mTop{ nullptr } {};
	Stack(int n) : LinkedList(n), mTop{ nullptr } {};

	~Stack();
	void AddNode(int num);
	void RemoveNode();
	void Info();
	void Print();
};

