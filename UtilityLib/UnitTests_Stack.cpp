#include "stdafx.h"
#include "UnitTests_Stack.h"
#include "Stack.h"

void UnitTests_Stack::RunBasicTests()
{
	printf("------ Stack testing --------\n");
	Stack<int> *stack = new Stack<int>();

	stack->push(2);

	stack->print();

	stack->push(4);
	stack->push(8);

	stack->print();

	stack->pop();
	stack->pop();

	stack->print();

	stack->push(4);
	stack->push(8);

	stack->push(16);
	stack->push(32);

	stack->print();

	stack->push(64);

	stack->print();

	this->m_result = UT_RESULT_SUCCESS;
}

void UnitTests_Stack::run()
{
	this->RunBasicTests();
}


UnitTests_Stack::UnitTests_Stack()
{
}


UnitTests_Stack::~UnitTests_Stack()
{
}
