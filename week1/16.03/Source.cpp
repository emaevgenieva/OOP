#include<iostream>
#include<vector>
#include<string>

template<typename T>

typename T::value_type fff(const T& c) {
	typedef T::value_type result = typename T::value_tyoe();
	for (typename T::const_iter it = c.begin(); it < c.end(); it) {
		if (*it < 0) {
			throw string("Negative num found");
		}

		result += *it;
	}
	return result / c.size();
}

int main() {

	try {
		std::vector<int> vect(5, 5);
		std::cout <<static_cast<int>( fff(vect));
	}
	catch (const std::string& s) {
		std::cout << s;
	}

	return 0;
}