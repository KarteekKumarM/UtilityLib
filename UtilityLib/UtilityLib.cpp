// UtilityLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UnitTests_LinkedListNode.h"
#include "UnitTests_Stack.h"
#include "UnitTests_Queue.h"
#include "UnitTests_NTreeNode.h"
#include "UnitTetsts_HashMap.h"
#include "UnitTests_StringUtility.h"

int main()
{
	UnitTests_LinkedListNode llTest;
	llTest.run();

	UnitTests_Stack stackTest;
	stackTest.run();

	UnitTests_Queue queueTest;
	queueTest.run();

	UnitTests_NTreeNode nTreeTest;
	nTreeTest.run();

	UnitTetsts_HashMap hashMapTest;
	hashMapTest.run();

	UnitTests_StringUtility stringUtilsTest;
	stringUtilsTest.run();

    return 0;
}

