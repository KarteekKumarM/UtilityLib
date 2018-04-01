#pragma once

template <class T>
class Iterator
{
public:
	virtual T current() = 0;
	virtual Iterator* next() = 0;

	Iterator();
	~Iterator();
};

template <class T>
inline Iterator<T>::Iterator()
{
}

template <class T>
inline Iterator<T>::~Iterator()
{
}
