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

template <class T>
inline void Stack<T>::push(T data)
{
	LinkedListNode<T> *newTop = new LinkedListNode<T>(data);
	if (isEmpty())
	{
		m_top = newTop;
		return;
	}

	newTop->m_next = m_top;
	m_top = newTop;
}

template <class T>
inline T Stack<T>::pop()
{
	if (isEmpty())
		return NULL;

	T data = m_top->m_data;
	m_top = m_top->m_next;
	return data;
}

template <class T>
inline T Stack<T>::peek()
{
	if (isEmpty())
		return NULL;

	return m_top->m_data;
}

template <class T>
inline bool Stack<T>::isEmpty()
{
	return m_top == NULL;
}

template <class T>
void Stack<T>::print()
{
	Stack<T> *reverseStack = new Stack<T>();

	LinkedListNode<T> *nodeIt = m_top;
	while (nodeIt != NULL)
	{
		reverseStack->push(nodeIt->m_data);
		nodeIt = nodeIt->m_next;
	}

	printf("{ ");
	while (!reverseStack->isEmpty())
	{
		T popped = reverseStack->pop();
		printf("%d ", popped);
	}
	printf("} \n");
}

template <class T>
inline Stack<T>::Stack()
{
	this->m_top = NULL;
}

template <class T>
inline Stack<T>::~Stack()
{
}