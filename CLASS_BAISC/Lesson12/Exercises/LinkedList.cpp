#include "LinkedList.h"
#include <iostream>


int LinkedList::GetCount(LinkedList& list)
{
	return list.mCnt;
}

void LinkedList::GetLink(LinkedList& origin, LinkedList& node, int data)
{
	node.mData = data;
	if (&origin != nullptr)
	{
		node.mLink = &origin;
		node.mCnt = origin.mCnt + 1;
	}
	else
	{
		node.mCnt = 1;
	}

}

int LinkedList::GetNum(LinkedList& instance)
{
	return instance.mData;
}

LinkedList* LinkedList::LinkSwap(LinkedList& origin)
{
	return origin.mLink;
}

bool LinkedList::CheckEmpty(LinkedList* instance)
{
	return instance->mLink != nullptr;
}

