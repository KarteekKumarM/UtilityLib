#include "stdafx.h"
#include "Stack.h"
#include "LinkedListNode.h"

template <class T>
void Stack<T>::push(T data)
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
T Stack<T>::pop()
{
	if (isEmpty())
		return NULL;

	T data = m_top->m_data;
	m_top = m_top->m_next;
	return data;
}

template <class T>
T Stack<T>::peek()
{
	if (isEmpty())
		return NULL;

	return m_top->m_data;
}

template <class T>
bool Stack<T>::isEmpty()
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
Stack<T>::Stack()
{
	this->m_top = NULL;
}

template <class T>
Stack<T>::~Stack()
{
}
