// UtilityLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UnitTests_LinkedListNode.h"
#include "UnitTests_Stack.h"


int main()
{
	UnitTests_LinkedListNode llTest;
	llTest.run();

	UnitTests_Stack stackTest;
	stackTest.run();

    return 0;
}

