#include "stdafx.h"
#include "NTreeNode.h"
#include "Stack.h"


NTreeNode::NTreeNode( int data )
{
	m_data = data;
	m_children = NULL;
}

void NTreeNode::addChild(NTreeNode *newNode)
{
	LinkedListNode<NTreeNode*> *childNode = new LinkedListNode<NTreeNode*>(newNode);
	if (m_children == NULL)
	{
		m_children = childNode;
		return;
	}

	m_children->addAtEnd(childNode);
}

NTreeNode* NTreeNode::depthFirstSearch(int data)
{
	Stack<NTreeNode*> *stackIt = new Stack<NTreeNode*>();
	stackIt->push(this);

	while (!stackIt->isEmpty())
	{
		NTreeNode *nodeIt = stackIt->pop();

		if (nodeIt->m_data == data)
			return nodeIt;

		LinkedListNode<NTreeNode*> *childIt = nodeIt->m_children;
		while (childIt != NULL)
		{
			stackIt->push(childIt->m_data);
			childIt = childIt->m_next;
		}
	}

	return NULL;
}

NTreeNode::~NTreeNode()
{
}
