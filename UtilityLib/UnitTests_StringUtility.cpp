#include "stdafx.h"
#include "UnitTests_StringUtility.h"
#include "StringUtility.h"

void UnitTests_StringUtility::RunBasicTests()
{
	printf("------ String Utility testing --------\n");

	char javaThing[] = "Java is kinda Great";

	this->m_result = UT_RESULT_SUCCESS;

	if (StringUtility::indexOf(javaThing, "kinda") != 8)
		this->m_result = UT_RESULT_FAIL;

	printf(javaThing);

	printf(" -> ");

	StringUtility::reverseWordsInString(javaThing, StringUtility::getLength(javaThing));

	printf(javaThing);

	printf("\n");
}

void UnitTests_StringUtility::run()
{
	this->RunBasicTests();
}


UnitTests_StringUtility::UnitTests_StringUtility()
{
}


UnitTests_StringUtility::~UnitTests_StringUtility()
{
}
