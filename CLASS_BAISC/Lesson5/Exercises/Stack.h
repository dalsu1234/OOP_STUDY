#pragma once
class Stack
{
	struct Node
	{
		Node* pNext{ nullptr };
		int mData{};
	};

	Node* pTop;
	int mCnt;
public:

	Stack() : pTop{ nullptr }, mCnt{ 0 } {};
	~Stack()
	{
		delete[] pTop;
		pTop = nullptr;
	}

	void Push(int data);
	void Pop();
	void Print();
	void StackPrint() const;
};

