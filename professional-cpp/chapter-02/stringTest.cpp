#include <iostream>
#include <string>

int main()
{
	std::string A("12");

	auto string1 = "hello world";
	auto string2 = "hello world"s;

	std::cout << string1 << std::endl;
	std::cout << string2 << std::endl;

	return 0;
}
