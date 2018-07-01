#include <iostream>
#include <cstring>


char* copyString(const char* str)
{
	std::cout << strlen(str) << std::endl;
	char* result = new char[strlen(str) + 1];
	strcpy(result, str);

	return result;
}

int main()
{
	char* retValue = copyString("Hello");
	std::cout << retValue << std::endl;	
	std::cout << strlen(retValue) << std::endl;	
	return 0;
}

