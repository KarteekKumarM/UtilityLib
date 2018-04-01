#include "stdafx.h"
#include "UnitTetsts_HashMap.h"
#include "HashMap.h"

void UnitTetsts_HashMap::RunBasicTests()
{
	HashMap<int, float> *map = new HashMap<int, float>();

	map->insert(5, 10.0);

	m_result = UT_RESULT_SUCCESS;

	if (map->search(5) == NULL)
		m_result = UT_RESULT_FAIL;

	if (map->search(141) != NULL)
		m_result = UT_RESULT_FAIL;

	delete map;
}

void UnitTetsts_HashMap::run()
{
	this->RunBasicTests();
}

UnitTetsts_HashMap::UnitTetsts_HashMap()
{

}

UnitTetsts_HashMap::~UnitTetsts_HashMap()
{
}
