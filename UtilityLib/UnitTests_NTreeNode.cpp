#include "stdafx.h"
#include "UnitTests_NTreeNode.h"
#include "NTreeNode.h"


void UnitTests_NTreeNode::RunBasicTests()
{
	NTreeNode *root = new NTreeNode(20);

	NTreeNode *eight = new NTreeNode(8);

	root->addChild(eight);
	root->addChild(new NTreeNode(22));

	NTreeNode *twelve = new NTreeNode(12);

	eight->addChild(new NTreeNode(4));
	eight->addChild(twelve);

	twelve->addChild(new NTreeNode(10));
	twelve->addChild(new NTreeNode(14));

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
