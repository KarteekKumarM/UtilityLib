#pragma once

template <class T>
class LinkedListNode
{
public:
	T m_data;
	LinkedListNode *m_next;

	// if index is larger than size of list, then it is appended to the end of the list
	void addAtIndex(LinkedListNode<T> *llNodeNew, unsigned int index);
	void addAtBeginning(LinkedListNode<T> *llNodeNew);
	void addAtEnd(LinkedListNode<T> *llNodeNew);
	LinkedListNode<T>* getLastNode();
	unsigned int getSize();
	void print();

	LinkedListNode<T>( T data );
	~LinkedListNode<T>();
};