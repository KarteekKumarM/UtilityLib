#include "stdafx.h"
#include "UnitTetsts_HashMap.h"
#include "HashMap.h"

void UnitTetsts_HashMap::RunBasicTests()
{
	HashMap<int, float> *map = new HashMap<int, float>();

	map->insert(5, 10.0);
	map->insert(15, 20.0);
	map->insert(25, 30.0);
	map->insert(HASHMAP_STORAGE_CAPACITY + 25, 1230.0);

	map->remove(HASHMAP_STORAGE_CAPACITY + 25);

	m_result = UT_RESULT_SUCCESS;

	if (map->search(25) == NULL)
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
