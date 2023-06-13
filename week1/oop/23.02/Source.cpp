#include<iostream>
#include<cstring>

class Student {
private:
	std::string m_name;
	int m_fn;
	bool m_hasHomeWork;
	float m_studyTime;
public:
	friend std::istream& operator >> (std::istream& in, Student& student);
	friend std::ostream& operator << (std::ostream& out, const Student& student);
};

//define right-shift
std::istream& operator >> (std::istream& in, Student& student) {

	return in >> student.m_name >> student.m_fn >> student.m_hasHomeWork >> student.m_studyTime;
}

std::ostream& operator << (std::ostream& out, const Student& student) {

	return out << student.m_name << " " << student.m_fn << " " << student.m_hasHomeWork << " " << student.m_studyTime;
}

int main() {
	Student student;
	Student student2;

	std::cin >> student;
	std::cout << student << std::endl;

	return 0;
}