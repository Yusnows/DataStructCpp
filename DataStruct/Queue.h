#pragma once

#include<iostream>
#include"node.h"


template<class T>
class ChainQueue
{
public:
	ChainQueue();
	~ChainQueue();

	bool push(T& value);
	bool pop(T& e);
	bool isEmpty()const;
	int whatSize()const;
	T front()const;

private:
	int count;
	node<T>*head;
	node<T>*tail;

};

template<class T>
inline ChainQueue<T>::ChainQueue()
{
	count = 0;
	head = new node<T>;
	tail = head;
}

template<class T>
inline ChainQueue<T>::~ChainQueue()
{
	while (head->next != nullptr)
	{
		node<T>*pdel = head;
		head = head->next;
		delete pdel;
	}
	delete head;
}

template<class T>
inline bool ChainQueue<T>::push(T & value)
{
	node<T>*pnode = new node<T>;
	tail->data = value;
	tail->next = pnode;
	tail = tail->next;
	count++;
	return true;
}

template<class T>
inline bool ChainQueue<T>::pop(T & e)
{
	if (!isEmpty())
	{
		e = head->data;
		node<T>*pdel = head;
		head = head->next;
		delete pdel;
		count--;
		return true;
	}
	else
		return false;
}

template<class T>
inline bool ChainQueue<T>::isEmpty() const
{
	if (head->next = nullptr)
		return true;
	else
		return false;
}

template<class T>
inline int ChainQueue<T>::whatSize() const
{
	return count;
}

template<class T>
inline T ChainQueue<T>::front() const
{
	return head->data;
}



template<class T>
class LoopQueue
{
public:
	LoopQueue(int cap=10);
	~LoopQueue();

	bool isEmpty()const;
	bool isFull()const;
	int whatSize()const;
	int whatBufferSize()const;
	bool push(T& value);
	bool pop(T& e)const;
	T front()const;

private:
	int capacity;
	int head;
	int tial;
//	int count;
	T *ptr;
};

template<class T>
inline LoopQueue<T>::LoopQueue(int cap=10)
{
	head = 0;
	tial = 0;
//	count = 0;
	capacity = cap;
	ptr = new T[capacity];
}

template<class T>
inline LoopQueue<T>::~LoopQueue()
{
	delete[]ptr;
}

template<class T>
inline bool LoopQueue<T>::isEmpty() const
{
	if (head == tial)
		return true;
	else
		return false;
}

template<class T>
inline bool LoopQueue<T>::isFull() const
{
//	if (count == capacity)
	if((tial+1)%capacity==head)
		return true;
	else
		return false;
}

template<class T>
inline int LoopQueue<T>::whatSize() const
{
	return (tial - head + capacity) % capacity;
//	return count;
}

template<class T>
inline int LoopQueue<T>::whatBufferSize() const
{
	return capacity;
}

template<class T>
inline bool LoopQueue<T>::push(T & value)
{
	if (!isFull())
	{
		ptr[tial] = value;
		tial = (tial + 1) % capacity;
		return true;
	}
	else
		return false;
}

template<class T>
inline bool LoopQueue<T>::pop(T & e) const
{
	if (!isEmpty)
	{
		e = ptr[head];
		begin = (begin + 1) % capacity;
		return true;
	}
	else
		return false;
}

template<class T>
inline T LoopQueue<T>::front() const
{
	if (!isEmpty())
	{
		return ptr[head];
	}
	else
		return false;
}
