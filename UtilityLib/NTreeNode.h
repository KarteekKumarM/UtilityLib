#pragma once

#include "LinkedListNode.h"

class NTreeNode
{
public:
	int m_data;
	LinkedListNode<NTreeNode*> *m_children;

	void addChild(NTreeNode *newNode);

	NTreeNode* depthFirstSearch(int data);

	NTreeNode( int data );
	~NTreeNode();
};

