#pragma once

#include "Constants.h"

template <class T>
class LinkedListNode
{
public:
	T m_data;
	LinkedListNode *m_next;

	// if index is larger than size of list, then it is appended to the end of the list
	void addAtIndex(LinkedListNode<T> *llNodeNew, unsigned int index);
	void addAtBeginning(LinkedListNode<T> *llNodeNew);
	void addAtEnd(LinkedListNode<T> *llNodeNew);
	LinkedListNode<T>* getLastNode();
	unsigned int getSize();
	void print();
	void removeAtindex(unsigned int index);

	LinkedListNode<T>( T data );
	~LinkedListNode<T>();
};

template <class T>
void LinkedListNode<T>::addAtIndex(LinkedListNode<T> *llNodeNew, unsigned int index)
{
	int itCounter = 0;

	LinkedListNode *llNodePrev = NULL;
	LinkedListNode *llNodeIt = this;
	while (itCounter != index && llNodeIt)
	{
		llNodePrev = llNodeIt;
		llNodeIt = llNodeIt->m_next;
		itCounter++;
	}

	if (llNodePrev == NULL)
	{
		// start of the list
		LinkedListNode *lastNodeInNewList = llNodeNew->getLastNode();
		lastNodeInNewList->m_next = this;
	}
	else if (llNodeIt == NULL)
	{
		// end of the list
		llNodePrev->m_next = llNodeNew;
	}
	else
	{
		// middle of this list
		LinkedListNode *lastNodeInNewList = llNodeNew->getLastNode();
		llNodePrev->m_next = llNodeNew;
		lastNodeInNewList->m_next = llNodeIt;
	}
}

template <class T>
inline void LinkedListNode<T>::addAtBeginning(LinkedListNode<T> * llNodeNew)
{
	this->addAtIndex(llNodeNew, 0);
}

template <class T>
inline void LinkedListNode<T>::addAtEnd(LinkedListNode<T> * llNodeNew)
{
	this->addAtIndex(llNodeNew, MAX_UINT);
}

template <class T>
inline LinkedListNode<T>* LinkedListNode<T>::getLastNode()
{
	LinkedListNode<T> *nodeIt = this;

	while (nodeIt->m_next != NULL)
		nodeIt = nodeIt->m_next;

	return nodeIt;
}

template <class T>
inline unsigned int LinkedListNode<T>::getSize()
{
	LinkedListNode<T> *nodeIt = this;

	unsigned int count = 0;
	while (nodeIt != NULL)
	{
		count++;
		nodeIt = nodeIt->m_next;
	}
	return count;
}

template <class T>
inline void LinkedListNode<T>::print()
{
	LinkedListNode<T> *nodeIt = this;

	printf("{ ");
	while (nodeIt != NULL)
	{
		printf("%d ", nodeIt->m_data);
		nodeIt = nodeIt->m_next;
	}
	printf("} \n");
}

template<class T>
inline void LinkedListNode<T>::removeAtindex(unsigned int index)
{
	int itCounter = 0;

	LinkedListNode *llNodePrev = NULL;
	LinkedListNode *llNodeIt = this;
	while (itCounter != index && llNodeIt)
	{
		llNodePrev = llNodeIt;
		llNodeIt = llNodeIt->m_next;
		itCounter++;
	}

	if (llNodePrev == NULL)
	{
		// start of the list
		// can't remove self
		// assert
	}
	else if (llNodeIt == NULL)
	{
		// end of the list
		llNodePrev->m_next = NULL;
	}
	else
	{
		// middle of this list
		llNodePrev->m_next = llNodeIt->m_next;
	}
}

template <class T>
LinkedListNode<T>::LinkedListNode(T data)
{
	this->m_data = data;
}


template <class T>
LinkedListNode<T>::~LinkedListNode()
{
}
