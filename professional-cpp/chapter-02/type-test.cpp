#include <iostream>
#include <string>
#include <typeinfo>  //for 'typeid' to work  

int main()
{
	int i = -7;
	unsigned us = 5U;
	long l = -7L;
	long long ll = 14LL;
	unsigned long ul = 5400UL;
	unsigned long long ull = 140ULL;
	float f = 7.2f;
	double d = 7.2;
	long double ld = 16.98L;

	std::string s_i = std::to_string(i);
	std::string s_us = std::to_string(us);
	std::string s_l = std::to_string(l);
	std::string s_ll = std::to_string(ll);
	std::string s_ul = std::to_string(ul);
	std::string s_ull = std::to_string(ull);
	std::string s_f = std::to_string(f);
	std::string s_d = std::to_string(d);
	std::string s_ld = std::to_string(ld);

	std::cout << "int i => " << s_i << ": " << typeid(s_i).name() << std::endl;
	std::cout << "unsigned us => " << s_us  << ": " << typeid(s_us).name() << std::endl;
	std::cout << "long l => " << s_l  << ": " << typeid(s_l).name() << std::endl;
	std::cout << "long long ll => " << s_ll  << ": " << typeid(s_ll).name() << std::endl;
	std::cout << "unsigned long ul =>" << s_ul  << ": " << typeid(s_ul).name() << std::endl;
	std::cout << "float f => " << s_f  << ": " << typeid(s_f).name() << std::endl;
	std::cout << "double d => " << s_d  << ": " << typeid(s_d).name() << std::endl;
	std::cout << "long double d => " << s_ld  << ": " << typeid(s_ld).name() << std::endl;
}


