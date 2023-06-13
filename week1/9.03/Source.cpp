#include<iostream>
#include<string>
#include<cctype>
void func(const std::string& str) {

	for (std::string::size_type i = 0; i < str.size(); i++) {

		std::cout << str[i] << std::endl;

	}
}

void printReverse(const std::string& str) {

	for (std::string::const_reverse_iterator it = str.rbegin(); it != str.rend(); it++) {

		std::cout << *it << ' ';
	}
}

void printFirstAndLastLetters(const std::string& str) {

	if (str.empty()) {
		return;
	}
	std::cout << static_cast<char>(tolower(str[0]));
	std::cout << static_cast<char>(tolower(str[str.size() - 1]));

}

void printString(std::string& str, const std::string& subStr) {

	if (str.find(subStr) != std::string::npos) {
		std::string::size_type pos = str.find(subStr);
	    str.replace(pos, "*");
	}

	std
	std::string::size_type pos = str.find(subStr);

	return result;
}

int main() {
	std::string myString = "Code";
	//func(myString);

	//printReverse(myString);

	printFirstAndLastLetters(myString);
	return 0;
}