#include "stdafx.h"
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

	if (root->depthFirstSearch(12) == twelve && root->depthFirstSearch(112) == NULL)
		m_result = UT_RESULT_SUCCESS;
	else
		m_result = UT_RESULT_FAIL;
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
