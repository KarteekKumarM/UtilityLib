#pragma once

#include "LinkedListNode.h"

#define HASHMAP_STORAGE_CAPACITY	1024

template <typename K, typename V>
class HashMap
{
private:
	struct Entry
	{
	public:
		K key;
		V value;
	};

	LinkedListNode<Entry*> *storage[HASHMAP_STORAGE_CAPACITY];

	unsigned int hash(K key);

public:
	void insert(K key, V value);
	V search(K key);

	HashMap();
	~HashMap();
};

template<typename K, typename V>
unsigned int HashMap<K, V>::hash(K key)
{
	// TODO : this only works for int right now
	return key % HASHMAP_STORAGE_CAPACITY;
}

template<typename K, typename V>
inline void HashMap<K, V>::insert(K key, V value)
{
	HashMap::Entry *entry = new Entry();
	entry->key = key;
	entry->value = value;

	unsigned int hashIndex = hash(key);

	LinkedListNode<Entry*> *llNodeEntry = new LinkedListNode<Entry*>(entry);
	if (storage[hashIndex] == NULL)
	{
		storage[hashIndex] = llNodeEntry;
	}
	else
	{
		LinkedListNode<Entry*> *llFirst = storage[hashIndex];
		llFirst->addAtBeginning(llNodeEntry);
	}
}

template<typename K, typename V>
inline V HashMap<K, V>::search(K key)
{
	unsigned int hashIndex = hash(key);
	if (storage[hashIndex] == NULL)
		return NULL;

	LinkedListNode<Entry*> *first = storage[hashIndex];
	while (first != NULL)
	{
		LinkedListNode<Entry*> *nodeIt = first;

		if (nodeIt->m_data->key == key)
			return nodeIt->m_data->value;

		first = first->m_next;
	}

	return NULL;
}

template <typename K, typename V>
inline HashMap<K, V>::HashMap()
{
	for (unsigned int i = 0; i < HASHMAP_STORAGE_CAPACITY; i++)
	{
		storage[i] = 0;
	}
}

template <typename K, typename V>
inline HashMap<K, V>::~HashMap()
{
	for (unsigned int i = 0; i < HASHMAP_STORAGE_CAPACITY; i++)
	{
		if (storage[i] != NULL)
		{
			LinkedListNode<Entry*> *first = storage[i];
			while (first != NULL)
			{
				LinkedListNode<Entry*> *nodeIt = first;
				first = first->m_next;
				delete nodeIt->m_data;
				delete nodeIt;
			}
		}
	}
}