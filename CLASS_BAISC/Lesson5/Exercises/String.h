#include <iostream>
#pragma once
class String
{
	char* mString;
	int mLength;
public:
	String(const char* string)
	{
		mLength = strlen(string);
		mString = new char[mLength + 1];
		Set(string);
	}
	~String()
	{
		delete[] mString;
		mString = nullptr;
	}
public:
	void Set(const char* string)
	{
		for (int i = 0; i < mLength; i++)
		{
			mString[i] = string[i];
		}
		mString[mLength] = '\0';
	}
	void Print() const
	{
		for (int i = 0; i < mLength; i++)
		{
			std::cout << mString[i];
		}
		std::cout << std::endl;
	}
};

