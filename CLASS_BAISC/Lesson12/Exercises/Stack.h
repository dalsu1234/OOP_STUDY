#pragma once
#include "LinkedList.h"
class Stack : public LinkedList
{
	LinkedList* mPin;

public:
	Stack() :mPin{nullptr} {};
	~Stack();

	
	void Push(int n);
	void Pop();
	void PrintInfo();
	void Print();


};

