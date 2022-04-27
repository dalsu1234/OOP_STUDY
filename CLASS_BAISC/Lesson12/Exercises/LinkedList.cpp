#include "LinkedList.h"

LinkedList::LinkedList(int n)
{
	mLink = nullptr;
	mData = n;
	mCount = 0;
}

void LinkedList::SetLink(LinkedList& top, LinkedList& node)
{
	if (top.mLink == nullptr)
	{
		top.mLink = &node;
	}
	else
	{
		node.mLink = top.mLink;
		top.mLink = &node;
	}
}


void LinkedList::NewLink(LinkedList& top)
{

	top.mLink = top.mLink->mLink;
}

void LinkedList::SwapLinkPoint(LinkedList& top, LinkedList& link)
{
	link.mLink = &top;
}

int LinkedList::GetData(LinkedList& top)
{
	return top.mData;
}

void LinkedList::GetCount(LinkedList& top)
{
	top.mCount++;
}


LinkedList* LinkedList::LinkPoint(LinkedList& link)
{
	return link.mLink;
}

LinkedList::~LinkedList()
{

}