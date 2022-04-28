#include "LinkedList.h"

LinkedList::LinkedList(int n)
{
	mLink = nullptr;
	mData = n;
	mCount = 0;
}

void LinkedList::SetLink(LinkedList& base, LinkedList& node)
{
	if (base.mLink == nullptr)
	{
		base.mLink = &node;
	}
	else
	{
		node.mLink = base.mLink;
		base.mLink = &node;
	}
}


void LinkedList::NewLink(LinkedList& base)
{

	base.mLink = base.mLink->mLink;
}

void LinkedList::SwapLinkPoint(LinkedList& base, LinkedList& link)
{
	link.mLink = &base;
}

int LinkedList::GetData(LinkedList& base)
{
	return base.mData;
}

void LinkedList::GetCount(LinkedList& base)
{
	base.mCount++;
}


LinkedList* LinkedList::LinkPoint(LinkedList& link)
{
	return link.mLink;
}

LinkedList::~LinkedList()
{

}