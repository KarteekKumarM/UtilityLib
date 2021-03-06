#include "stdafx.h"
#include "UnitTests_LinkedListNode.h"
#include "LinkedListNode.h"

void UnitTests_LinkedListNode::RunAddTests()
{
	printf("------ Linked List testing --------\n");

	LinkedListNode<int> *realFirst = new LinkedListNode<int>(2);

	LinkedListNode<int> *first = new LinkedListNode<int>(4);
	first->addAtBeginning(realFirst);
	first->addAtEnd(new LinkedListNode<int>(8));
	first->addAtEnd(new LinkedListNode<int>(32));
	first->addAtEnd(new LinkedListNode<int>(64));
	first->addAtIndex(new LinkedListNode<int>(16), 2);

	realFirst->print();

	while (realFirst != NULL)
	{
		LinkedListNode<int> *nodeIt = realFirst;
		realFirst = realFirst->m_next;
		delete nodeIt;
	}

	this->m_result = UT_RESULT_SUCCESS;
}

void UnitTests_LinkedListNode::run()
{
	this->RunAddTests();
}


UnitTests_LinkedListNode::UnitTests_LinkedListNode()
{
}


UnitTests_LinkedListNode::~UnitTests_LinkedListNode()
{
}
