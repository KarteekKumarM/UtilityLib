#pragma once

#include <stdlib.h>

#include "LinkedListNode.h"
#include "Stack.h"
#include "Queue.h"
#include "Iterator.h"

#define SERIALIZE_BUFFER_SIZE			512
#define SERIALIZE_MAX_NODE_DATA_LENGTH	12

template <class T>
class NTreeNode
{
public:
	T m_data;
	LinkedListNode<NTreeNode*> *m_children;

	void addChild(NTreeNode *newNode);

	NTreeNode<T>* depthFirstSearch(T data);
	NTreeNode<T>* breadthFirstSearch(T data);

	void serialize(char outSerializedString[SERIALIZE_BUFFER_SIZE]);
	static NTreeNode<T>* deserialize(const char inSerializedString[SERIALIZE_BUFFER_SIZE]);

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
void NTreeNode<T>::serialize(char outSerializedString[SERIALIZE_BUFFER_SIZE])
{
	Stack<NTreeNode*> *stackIt = new Stack<NTreeNode*>();
	stackIt->push(this);

	char *printPointer = outSerializedString;

	printPointer += sprintf_s(printPointer, SERIALIZE_MAX_NODE_DATA_LENGTH, "%d#", (int)(this->m_data));

	while (!stackIt->isEmpty())
	{
		NTreeNode *nodeIt = stackIt->pop();

		LinkedListNode<NTreeNode*> *childIt = nodeIt->m_children;

		while (childIt != NULL)
		{
			stackIt->push(childIt->m_data);

			printPointer += sprintf_s(printPointer, SERIALIZE_MAX_NODE_DATA_LENGTH, "%d", childIt->m_data->m_data);

			childIt = childIt->m_next;

			if ( childIt )
				printPointer += sprintf_s(printPointer, SERIALIZE_MAX_NODE_DATA_LENGTH, ",");
		}
		printPointer += sprintf_s(printPointer, SERIALIZE_MAX_NODE_DATA_LENGTH, "#");
	}
}

// TODO : make this a static function
template <class T>
NTreeNode<T>* NTreeNode<T>::deserialize(const char inSerializedString[SERIALIZE_BUFFER_SIZE])
{
	NTreeNode<T> *rootNode = NULL;
	Stack<NTreeNode*> *stackIt = new Stack<NTreeNode*>();
	LinkedListNode<NTreeNode*> *readChildren = NULL;

	int readCount = 0;
	char inNumberString[SERIALIZE_BUFFER_SIZE];
	char inNumberPointer = 0;
	while (readCount < SERIALIZE_BUFFER_SIZE && inSerializedString[readCount] != '\0')
	{
		char inChar = inSerializedString[readCount];
		if (inChar == '#' || inChar == ',')
		{
			if (inNumberPointer > 0)
			{
				inNumberString[inNumberPointer++] = '\0';
				int inNumber = atoi(inNumberString);
				NTreeNode<T> *inNode = new NTreeNode(inNumber);
				LinkedListNode<NTreeNode*> *inLlNode = new LinkedListNode<NTreeNode*>(inNode);

				if (readChildren == NULL)
					readChildren = inLlNode;
				else
					readChildren->addAtEnd(inLlNode);

				if ( inChar == '#' )
				{
					if (stackIt->isEmpty())
					{
						rootNode = inNode;
						// assert : rootNode == readChildren
						stackIt->push(inNode);
					}
					else
					{
						NTreeNode<T> *nodeToInsertAt = stackIt->pop();
						while (readChildren != NULL)
						{
							nodeToInsertAt->addChild(readChildren->m_data);
							stackIt->push(readChildren->m_data);
							readChildren = readChildren->m_next;
						}
					}
					readChildren = NULL;
				}
				inNumberPointer = 0;
			}
			else if (inChar == '#')
				stackIt->pop();
		}
		else
		{
			inNumberString[inNumberPointer++] = inChar;
		}

		readCount++;
	}
	return rootNode;
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