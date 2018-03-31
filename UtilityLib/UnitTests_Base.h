#pragma once

enum UnitTestResult
{
	UT_RESULT_INVALID,
	UT_RESULT_SUCCESS,
	UT_RESULT_FAIL
};

// abstract class
// this is abstract because it has atleast 1 pure virtual function
class UnitTests_Base
{
public:
	UnitTestResult m_result;

	// pure virtual functions
	virtual void run() = 0;

	UnitTests_Base();
	~UnitTests_Base();
};

