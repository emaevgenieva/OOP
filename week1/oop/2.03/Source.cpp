#include<iostream>
#include<vector>
#include<list>
#include<string>

class Foo {
private:

public:
	Foo(int f) {

	}
};

int main() {

	/*std::vector<int> vec(10, 5);
	std::list<int>ls(vec.begin(), vec.begin() + vec.size()/2);
	std::list<int>ls2(vec.begin(), vec.begin() + (vec.end() - vec.begin()) / 2);*/

	std::list<Foo>f;

	//Foo f;


	std::list<std::vector<std::string>> list;
	std::vector<std::string> vec;
	vec.push_back(std::string("abc"));
	vec.push_back("def");

	list.push_back(vec);
	vec.clear();

	vec.push_back("456");
	vec.push_back("123");
	list.push_back(vec);


	for (std::list<std::vector<std::string>>::iterator itRow = list.end(); itRow != list.begin(); itRow--) {
		for (std::vector<std::string>::iterator itWord = itRow->begin(); itWord != itRow->end(); itWord++) {
			std::cout << *itWord << std::endl;
		}
	}

	for (std::list<std::vector<std::string>>::const_reverse_iterator itRow = list.rbegin(); itRow != list.rend(); itRow++) {
		for (std::vector<std::string>::const_iterator itWord = itRow->begin(); itWord != itRow->end(); itWord++) {
			std::cout << *itWord << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
	
}