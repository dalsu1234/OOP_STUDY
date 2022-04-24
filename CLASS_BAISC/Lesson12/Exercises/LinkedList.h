#pragma once
#include <iostream>
class LinkedList
{
protected:
	
	int mCnt;
	int mData;
	LinkedList* mLink;

public:

	LinkedList() : mCnt{ 0 }, mData{0}, mLink{ nullptr }{};
	
	//virtual ~LinkedList();// ¿¡·¯

	int GetCount(LinkedList& list);
	
	void GetLink(LinkedList& origin, LinkedList& node, int data);
	int GetNum(LinkedList& instance);
	LinkedList* LinkSwap(LinkedList& origin);
	bool CheckEmpty(LinkedList* instance);

	virtual void Push(int n) = 0;
	virtual void Pop() = 0;
	virtual void PrintInfo() = 0;
	virtual void Print() = 0;

	


	
};

