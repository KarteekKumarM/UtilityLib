#include "stdafx.h"

#include <stdlib.h>
#include <string.h>

#include "UnitTests_NTreeNode.h"
#include "NTreeNode.h"


void UnitTests_NTreeNode::RunBasicTests()
{
	NTreeNode<int> *root = new NTreeNode<int>(20);

	NTreeNode<int> *eight = new NTreeNode<int>(8);

	root->addChild(eight);
	root->addChild(new NTreeNode<int>(22));

	NTreeNode<int> *twelve = new NTreeNode<int>(12);

	eight->addChild(new NTreeNode<int>(4));
	eight->addChild(twelve);

	twelve->addChild(new NTreeNode<int>(10));
	twelve->addChild(new NTreeNode<int>(14));

	m_result = UT_RESULT_SUCCESS;

	if (root->depthFirstSearch(12) != twelve)
		m_result = UT_RESULT_FAIL;

	if (root->depthFirstSearch(112) != NULL)
		m_result = UT_RESULT_FAIL;

	if (root->breadthFirstSearch(12) != twelve)
		m_result = UT_RESULT_FAIL;

	if (root->breadthFirstSearch(112) != NULL)
		m_result = UT_RESULT_FAIL;

	char serializeBuffer[512];
	// expected : "20#8,22##4,12#10,14####"
	root->serialize(serializeBuffer);

	NTreeNode<int> *readRoot = NTreeNode<int>::deserialize(serializeBuffer);

	char reserializeBuffer[512];
	readRoot->serialize(reserializeBuffer);

	if (strcmp(serializeBuffer, reserializeBuffer))
		m_result = UT_RESULT_FAIL;

	// clean up
	Iterator<NTreeNode<int>*> *iterator = new NTreeNode<int>::BfsIterator(root);
	while (iterator != NULL)
	{
		NTreeNode<int> *nodeIt = iterator->current();
		iterator = iterator->next();
		delete nodeIt;
	}

}

void UnitTests_NTreeNode::run()
{
	RunBasicTests();
}

UnitTests_NTreeNode::UnitTests_NTreeNode()
{
}


UnitTests_NTreeNode::~UnitTests_NTreeNode()
{
}
