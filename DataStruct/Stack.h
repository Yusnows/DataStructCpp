#pragma once
#include<iostream>
#include"node.h"

using namespace std;

template<class T>
class ArrayStack
{
public:
	ArrayStack();
	~ArrayStack();
	int push(const T &data);
	bool pop(T& e);
	bool isEmpty()const;
	bool isFull()const;
	T operator[](int index);
	int whatSize()const;
	int whatBufferSize()const;
	T Top()const;

private:
	int size;
	int top;
	T *ptr;
};

template<class T>
inline ArrayStack<T>::ArrayStack()
{
	size = 100;
	top = -1;
	ptr = new T[size];
}

template<class T>
inline ArrayStack<T>::~ArrayStack()
{
	delete[]ptr;
}

template<class T>
inline int ArrayStack<T>::push(const T & data)
{
	if (!isFull())
	{
		ptr[++top] = data;
	}
	else
	{
		ptr = (T*)realloc(ptr, (size + 10) * sizeof(T));
		ptr[++top] = data;
		size += 10;
	}
	return 0;
}

template<class T>
inline bool ArrayStack<T>::pop(T& e)
{
	if (!isEmpty())
	{
		e = ptr[top--];
		return true;
	}
	else
		return false;
}

template<class T>
inline bool ArrayStack<T>::isEmpty() const
{
	return top<=-1;
}

template<class T>
inline bool ArrayStack<T>::isFull() const
{
	return top==size-1;
}

template<class T>
inline T ArrayStack<T>::operator[](int index)
{
	if (index < size)
		return T(ptr[index]);
	else
		return T(0);
}

template<class T>
inline int ArrayStack<T>::whatSize() const
{
	return top+1;
}

template<class T>
inline int ArrayStack<T>::whatBufferSize() const
{
	return size;
}

template<class T>
inline T ArrayStack<T>::Top() const
{
	if (!isEmpty())
		return T(ptr[top]);
	else
		return T("N");
}



template<class T>
class ChainStack
{
public:
	ChainStack();
	~ChainStack();

	bool push(const T&data);
	bool pop(T& e);
	bool isEmpty()const;
	int whatSize()const;
	T Top();

	
private:
	node<T>*phead;
	int count;
};

template<class T>
inline ChainStack<T>::ChainStack()
{
	count = 0;
	phead = new node<T>;
}

template<class T>
inline ChainStack<T>::~ChainStack()
{
	while (phead->next != nullptr)
	{
		node<T>*pdel = phead->next;
		phead->next = pdel->next;
		delete pdel;
	}
	delete phead;
}

template<class T>
inline bool ChainStack<T>::push(const T & data)
{
	node<T>*pnode = new node<T>(data);
	pnode->next = phead->next;
	phead->next = pnode;
	count++;
	return true;
}

template<class T>
inline bool ChainStack<T>::pop(T & e)
{
	if (!isEmpty())
	{
		node<T>*pdel = phead->next;
		e = pdel->data;
		phead->next = pdel->next;
		delete pdel;
		count--;
		return true;
	}
	else
	{
		return false;
	}

}

template<class T>
inline bool ChainStack<T>::isEmpty() const
{
	if (phead->next == nullptr)
		return true;
	else
		return false;
}

template<class T>
int ChainStack<T>::whatSize() const
{
	return count;
}

template<class T>
T ChainStack<T>::Top()
{
	cout << count << endl;
	if (count != 0)
		return T(phead->next->data);
	else
		return T("N");
}
