#pragma once

#include "LinkedListNode.h"
#include "Stack.h"
#include "Queue.h"

template <class T>
class NTreeNode
{
public:
	T m_data;
	LinkedListNode<NTreeNode*> *m_children;

	void addChild(NTreeNode *newNode);

	NTreeNode<T>* depthFirstSearch(T data);
	NTreeNode<T>* breadthFirstSearch(T data);

	NTreeNode<T>( T data );
	~NTreeNode<T>();

	class DfsIterator
	{
	private:
		Stack<NTreeNode*> *stackIt;
	public:
		NTreeNode<T> *current;

		DfsIterator* next()
		{
			if (stackIt->isEmpty())
				return NULL;

			current = stackIt->pop();

			LinkedListNode<NTreeNode*> *childIt = current->m_children;
			while (childIt != NULL)
			{
				stackIt->push(childIt->m_data);
				childIt = childIt->m_next;
			}

			return this;
		}

		DfsIterator(NTreeNode *root)
		{
			stackIt = new Stack<NTreeNode*>();
			stackIt->push(root);
		}

		~DfsIterator()
		{
			delete stackIt;
		}
	};

	class BfsIterator
	{
	private:
		Queue<NTreeNode*> *queueIt;
	public:
		NTreeNode<T> *current;

		BfsIterator* next()
		{
			if (queueIt->isEmpty())
				return NULL;

			current = queueIt->pop();

			LinkedListNode<NTreeNode*> *childIt = current->m_children;
			while (childIt != NULL)
			{
				queueIt->push(childIt->m_data);
				childIt = childIt->m_next;
			}

			return this;
		}

		BfsIterator(NTreeNode *root)
		{
			queueIt = new Queue<NTreeNode*>();
			queueIt->push(root);
		}

		~BfsIterator()
		{
			delete queueIt;
		}
	};
};

template <class T>
inline void NTreeNode<T>::addChild(NTreeNode *newNode)
{
	LinkedListNode<NTreeNode*> *childNode = new LinkedListNode<NTreeNode*>(newNode);
	if (m_children == NULL)
	{
		m_children = childNode;
		return;
	}

	m_children->addAtEnd(childNode);
}

template <class T>
NTreeNode<T>* NTreeNode<T>::depthFirstSearch(T data)
{
	DfsIterator *iterator = new DfsIterator(this);
	iterator = iterator->next();
	while (iterator != NULL)
	{
		if (iterator->current->m_data == data)
			return iterator->current;

		iterator = iterator->next();
	}

	return NULL;
}

template <class T>
NTreeNode<T>* NTreeNode<T>::breadthFirstSearch(T data)
{
	BfsIterator *iterator = new BfsIterator(this);
	iterator = iterator->next();
	while (iterator != NULL)
	{
		if (iterator->current->m_data == data)
			return iterator->current;

		iterator = iterator->next();
	}

	return NULL;
}

template <class T>
inline NTreeNode<T>::NTreeNode(T data)
{
	m_data = data;
	m_children = NULL;
}

template <class T>
inline NTreeNode<T>::~NTreeNode()
{
}