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

// If you, at the bottom of the implementation cpp file, do explicit instantiation of all the types the template will be used with, the linker will be able to find them as usual.
template class Stack<int>;