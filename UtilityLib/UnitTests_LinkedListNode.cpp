#include "stdafx.h"
#include "UnitTests_LinkedListNode.h"
#include "LinkedListNode.h"

void UnitTests_LinkedListNode::RunAddTests()
{
	LinkedListNode *realFirst = new LinkedListNode(2);

	LinkedListNode *first = new LinkedListNode(4);
	first->addAtBeginning(realFirst);
	first->addAtEnd(new LinkedListNode(8));
	first->addAtEnd(new LinkedListNode(32));
	first->addAtEnd(new LinkedListNode(64));
	first->addAtIndex(new LinkedListNode(16), 2);

	realFirst->print();
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
