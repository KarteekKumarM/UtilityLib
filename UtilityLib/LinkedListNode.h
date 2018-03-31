#pragma once
class LinkedListNode
{
public:
	int m_data;
	LinkedListNode *m_next;

	// if index is larger than size of list, then it is appended to the end of the list
	void addAtIndex(LinkedListNode *llNodeNew, unsigned int index);
	void addAtBeginning(LinkedListNode *llNodeNew);
	void addAtEnd(LinkedListNode *llNodeNew);
	LinkedListNode* getLastNode();
	unsigned int getSize();
	void print();

	LinkedListNode( int pData );
	~LinkedListNode();
};

