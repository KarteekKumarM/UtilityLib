#pragma once

#include "LinkedListNode.h"

template <class T>
class Queue
{
private:
	LinkedListNode<T> *m_first;
public:
	void push(T data);
	T pop();
	T peek();
	bool isEmpty();
	void print();

	Queue<T>();
	~Queue<T>();
};

template<class T>
inline void Queue<T>::push(T data)
{
	LinkedListNode<T> *newNode = new LinkedListNode<T>(data);
	if (m_first == NULL)
	{
		m_first = newNode;
		return;
	}

	m_first->addAtEnd(newNode);
}

template<class T>
inline T Queue<T>::pop()
{
	if (isEmpty())
		return NULL;

	T data = m_first->m_data;
	m_first = m_first->m_next;
	return data;
}

template<class T>
inline T Queue<T>::peek()
{
	if (isEmpty())
		return NULL;
 
	return m_first->m_data;
}

template<class T>
inline bool Queue<T>::isEmpty()
{
	return m_first == NULL;
}

template<class T>
inline void Queue<T>::print()
{
	m_first->print();
}

template<class T>
inline Queue<T>::Queue()
{
}


template<class T>
inline Queue<T>::~Queue()
{
}
