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
	void SetLink(LinkedList& base, LinkedList& node);
	void NewLink(LinkedList& base);

	void SwapLinkPoint(LinkedList& base, LinkedList& link);
	int GetData(LinkedList& base);
	void GetCount(LinkedList& base);
	
	LinkedList* LinkPoint(LinkedList& link);

	virtual void AddNode(int num) = 0;
	virtual void RemoveNode() = 0;
	virtual void Info() = 0;
	virtual void Print() = 0;
};

