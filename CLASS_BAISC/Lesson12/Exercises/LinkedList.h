#pragma once
class LinkedList
{


protected:
	LinkedList* mLink;
	int mData;
	int mCount;

public:

	LinkedList() : mLink{ nullptr }, mData{}, mCount{}{};
	LinkedList(int n);
	virtual ~LinkedList();
	void SetLink(LinkedList& top, LinkedList& node);
	void NewLink(LinkedList& top);

	void SwapLinkPoint(LinkedList& top, LinkedList& link);
	int GetData(LinkedList& top);
	void GetCount(LinkedList& top);
	
	LinkedList* LinkPoint(LinkedList& link);

	virtual void AddNode(int num) = 0;
	virtual void RemoveNode() = 0;
	virtual void Info() = 0;
	virtual void Print() = 0;
};

