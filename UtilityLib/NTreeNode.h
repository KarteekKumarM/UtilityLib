#pragma once

#include "LinkedListNode.h"
#include "Stack.h"
#include "Queue.h"
#include "Iterator.h"

template <class T>
class NTreeNode
{
public:
	T m_data;
	LinkedListNode<NTreeNode*> *m_children;

	void addChild(NTreeNode *newNode);

	NTreeNode<T>* depthFirstSearch(T data);
	NTreeNode<T>* breadthFirstSearch(T data);

	NTreeNode<T>(T data);
	~NTreeNode<T>();

	class DfsIterator : public Iterator<NTreeNode*>
	{
	private:
		Stack<NTreeNode*> *m_stackIt;
		NTreeNode<T> *m_current;
	public:
		NTreeNode<T>* current()
		{
			return m_current;
		}

		Iterator<NTreeNode*>* next()
		{
			if (m_stackIt->isEmpty())
				return NULL;

			m_current = m_stackIt->pop();

			LinkedListNode<NTreeNode*> *childIt = m_current->m_children;
			while (childIt != NULL)
			{
				m_stackIt->push(childIt->m_data);
				childIt = childIt->m_next;
			}

			return this;
		}

		DfsIterator(NTreeNode *root)
		{
			m_stackIt = new Stack<NTreeNode*>();
			m_stackIt->push(root);

			next();
		}

		~DfsIterator()
		{
			delete stackIt;
		}
	};

	class BfsIterator : public Iterator<NTreeNode*>
	{
	private:
		Queue<NTreeNode*> *m_queueIt;
		NTreeNode<T> *m_current;
	public:
		NTreeNode<T>* current()
		{
			return m_current;
		}

		Iterator<NTreeNode*>* next()
		{
			if (m_queueIt->isEmpty())
				return NULL;

			m_current = m_queueIt->pop();

			LinkedListNode<NTreeNode*> *childIt = m_current->m_children;
			while (childIt != NULL)
			{
				m_queueIt->push(childIt->m_data);
				childIt = childIt->m_next;
			}

			return this;
		}

		BfsIterator(NTreeNode *root)
		{
			m_queueIt = new Queue<NTreeNode*>();
			m_queueIt->push(root);

			next();
		}

		~BfsIterator()
		{
			delete m_queueIt;
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
	Iterator<NTreeNode*> *iterator = new DfsIterator(this);
	while (iterator != NULL)
	{
		if (iterator->current()->m_data == data)
			return iterator->current();

		iterator = iterator->next();
	}

	return NULL;
}

template <class T>
NTreeNode<T>* NTreeNode<T>::breadthFirstSearch(T data)
{
	Iterator<NTreeNode*> *iterator = new BfsIterator(this);
	while (iterator != NULL)
	{
		if (iterator->current()->m_data == data)
			return iterator->current();

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