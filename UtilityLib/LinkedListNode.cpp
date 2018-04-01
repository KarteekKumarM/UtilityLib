#include "stdafx.h"
#include "LinkedListNode.h"

#include "Globals.h"

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
void LinkedListNode<T>::addAtBeginning(LinkedListNode<T> * llNodeNew)
{
	this->addAtIndex(llNodeNew, 0);
}

template <class T>
void LinkedListNode<T>::addAtEnd(LinkedListNode<T> * llNodeNew)
{
	this->addAtIndex(llNodeNew, MAX_UINT);
}

template <class T>
LinkedListNode<T>* LinkedListNode<T>::getLastNode()
{
	LinkedListNode<T> *nodeIt = this;
	
	while (nodeIt->m_next != NULL)
		nodeIt = nodeIt->m_next;

	return nodeIt;
}

template <class T>
unsigned int LinkedListNode<T>::getSize()
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
void LinkedListNode<T>::print()
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

template <class T>
LinkedListNode<T>::LinkedListNode( T data )
{
	this->m_data = data;
}


template <class T>
LinkedListNode<T>::~LinkedListNode()
{
}


// If you, at the bottom of the implementation cpp file, do explicit instantiation of all the types the template will be used with, the linker will be able to find them as usual.
template class LinkedListNode<int>;
class NTreeNode;
template class LinkedListNode<NTreeNode*>;