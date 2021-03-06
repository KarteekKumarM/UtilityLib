#pragma once
class StringUtility
{
public:
	static unsigned int getLength(char *str);
	static void reverseString(char *str, unsigned int length);
	static void reverseWordsInString(char *str, unsigned int length);
	static unsigned int indexOf(const char * str, const char * substr);

	StringUtility();
	~StringUtility();
};

