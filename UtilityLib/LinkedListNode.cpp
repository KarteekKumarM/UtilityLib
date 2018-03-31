#include "stdafx.h"
#include "LinkedListNode.h"

#include "Globals.h"

void LinkedListNode::addAtIndex(LinkedListNode *llNodeNew, unsigned int index)
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

void LinkedListNode::addAtBeginning(LinkedListNode * llNodeNew)
{
	this->addAtIndex(llNodeNew, 0);
}

void LinkedListNode::addAtEnd(LinkedListNode * llNodeNew)
{
	this->addAtIndex(llNodeNew, MAX_UINT);
}

LinkedListNode* LinkedListNode::getLastNode()
{
	LinkedListNode *nodeIt = this;
	
	while (nodeIt->m_next != NULL)
		nodeIt = nodeIt->m_next;

	return nodeIt;
}

unsigned int LinkedListNode::getSize()
{
	LinkedListNode *nodeIt = this;

	unsigned int count = 0;
	while (nodeIt != NULL)
	{
		count++;
		nodeIt = nodeIt->m_next;
	}
	return count;
}

void LinkedListNode::print()
{
	LinkedListNode *nodeIt = this;

	printf("{ ");
	while (nodeIt != NULL)
	{
		printf("%d ", nodeIt->m_data);
		nodeIt = nodeIt->m_next;
	}
	printf("} \n");
}

LinkedListNode::LinkedListNode( int pData )
{
	this->m_data = pData;
}


LinkedListNode::~LinkedListNode()
{
}
