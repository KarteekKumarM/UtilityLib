#include "stdafx.h"
#include "StringUtility.h"


unsigned int StringUtility::getLength(char * str)
{
	unsigned int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

void StringUtility::reverseString(char * str, unsigned int length)
{
	unsigned int i = 0;
	unsigned int j = length - 1;

	while (i < j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;

		i++;
		j--;
	}
}

void StringUtility::reverseWordsInString(char * str, unsigned int length)
{
	unsigned int i = 0;
	char *wordStart = str;
	unsigned int wordLetterCount = 0;
	while (i <= length)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			reverseString(wordStart, wordLetterCount);

			i++;

			wordLetterCount = 0;
			wordStart = &str[i];
			continue;
		}

		wordLetterCount++;

		i++;
	}

	reverseString(str, length);
}

StringUtility::StringUtility()
{
}


StringUtility::~StringUtility()
{
}
