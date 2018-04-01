// UtilityLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UnitTests_LinkedListNode.h"
#include "UnitTests_Stack.h"
#include "UnitTests_NTreeNode.h"

int main()
{
	UnitTests_LinkedListNode llTest;
	llTest.run();

	UnitTests_Stack stackTest;
	stackTest.run();

	UnitTests_NTreeNode nTreeTest;
	nTreeTest.run();

    return 0;
}

