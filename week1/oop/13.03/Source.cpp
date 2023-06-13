#include<iostream>

template <typename T>
T sum(const T& temp1,const T& temp2) {

	return temp1 + temp2;
}

template <typename T>
size_t difference(const T& temp1, const T& temp2) {

	return temp1 - temp2;
}
//int sum(const int &temp1, const int &temp2) {
//
//	return temp1 + temp2;
//}

int main() {

	std::cout << sum(3, 4) << std::endl;
	std::cout << sum(std::string("hi"), std::string("hey")) << std::endl;
	std::cout << difference((const char *)"hello", (const char*)"hi") << std::endl;
	std::cout << sum((const char*)"hello", (const char*)"hi") << std::endl;


	return 0;
}