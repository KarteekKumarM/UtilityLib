#pragma once

#include "LinkedListNode.h"

template <class T>
class Stack
{
private:
	LinkedListNode<T> *m_top;
public:
	void push(T data);
	T pop();
	T peek();
	bool isEmpty();
	void print();

	Stack<T>();
	~Stack<T>();
};