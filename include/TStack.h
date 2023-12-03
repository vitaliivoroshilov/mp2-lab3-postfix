#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
using namespace std;

const int MaxStackSize = 100;

template <class T>
class TStack
{
private:
	T* pMem;
	int top;
	int memSize;

public:

	TStack(int _n = MaxStackSize) : memSize(_n)
	{
		if ((memSize < 0) || (memSize > MaxStackSize))
			throw("");
		pMem = new T[memSize];
		top = 0;
	}

	TStack(const TStack& s) : memSize(s.memSize), top(s.top)
	{
		pMem = new T[memSize];
		for (int i = 0; i < memSize; i++)
			pMem[i] = s.pMem[i];
	}

	~TStack()
	{
		delete[] pMem;
	}

	void push(T elem)
	{
		if (top == memSize)
		{
			memSize *= 1.3;
			T* tmpMem = new T[memSize];
			for (int i = 0; i < top; i++)
				tmpMem[i] = pMem[i];
			delete[] pMem;
			pMem = tmpMem;
		}
		pMem[top++] = elem;
	}

	int getSize()
	{
		return top;
	}

	int getMemSize()
	{
		return memSize;
	}

	bool isEmpty()
	{
		return top == 0;
	}

	T getTop()
	{
		if (isEmpty())
			throw("");
		else
			return pMem[top - 1];
	}

	T pop()
	{
		if (isEmpty())
			throw("");
		else
			return pMem[--top];
	}

	bool operator==(const TStack& s)
	{
		if (top != s.top)
			return false;
		else
			for (int i = 0; i < top; i++)
				if (pMem[i] != s.pMem[i])
					return false;
		return true;
	}

	friend ostream& operator<<(ostream& out, const TStack& s)
	{
		for (int i = 0; i < s.top; i++)
			out << s.pMem[i] << " ";
		return out;
	}
};

#endif