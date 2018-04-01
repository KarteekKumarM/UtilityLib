#include "stdafx.h"
#include "UnitTests_Queue.h"

#include "Queue.h"


void UnitTests_Queue::RunBasicTests()
{
	printf("------ Stack testing --------\n");
	Queue<int> *queue = new Queue<int>();

	queue->push(2);

	queue->print();

	queue->push(4);
	queue->push(8);

	queue->print();

	queue->pop();
	queue->pop();

	queue->print();

	queue->push(4);
	queue->push(8);

	queue->push(16);
	queue->push(32);

	queue->print();

	queue->push(64);

	queue->print();

	this->m_result = UT_RESULT_SUCCESS;

	delete queue;
}

void UnitTests_Queue::run()
{
	this->RunBasicTests();
}

UnitTests_Queue::UnitTests_Queue()
{
}

UnitTests_Queue::~UnitTests_Queue()
{
}
