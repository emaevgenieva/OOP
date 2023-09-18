/*Task 2: Create a class Student. The student should have a name (character string of arbitrary length),
faculty number which has to be generated randomly and array of marks with arbitrary length. Create set
and get methods of your choice.  After that create a function which gets an array of Students (can be a
vector too) and a name and output the GPA of the student.*/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Student.hpp"

int Student::generateFacultyNumber(){
    return rand();
}

void Student::cleanup(){
    delete[] name;
}

void Student::copy(const Student& other){
    name = new char[strlen(other.name) +1]{'\0'};
    strcpy(name, other.name);

    facultyNumber = other.facultyNumber;
    marks = other.marks;
}

Student::Student(const char* _name, int _facultyNumber)
    : name(nullptr), facultyNumber(_facultyNumber){
    if(_name){
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
}

Student::Student(const Student& other){
    copy(other);
}

Student& Student::operator=(const Student& other){
    if(this != &other){
        cleanup();
        copy(other);
    }   
    return *this;
}

Student::~Student(){
    cleanup();
};

char* Student::getName()const{
    return name;
}

int Student::getFacultyNumber()const{
    return facultyNumber;
}

std::vector<double> Student::getMarks()const{
    return marks;
}

void Student::setName(const char* _name){
    strcpy(name, _name);
}

void Student::setFAcultyNumber(int _facultyNumber){
    facultyNumber = _facultyNumber;
}

void Student::setMarks(const std::vector<double>& studentMarks){
    marks = studentMarks;
}

void Student::print() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Faculty Number: " << facultyNumber << std::endl;
    std::cout << "Marks: ";
    for (std::size_t i = 0; i < marks.size(); ++i) {
        std::cout << marks[i] << " ";
    }
    std::cout << std::endl;
}

double Student::calculateGPA(const std::vector<double>& marks) const{
    double totalMarks = 0.0;
    for(std::size_t i = 0; i < marks.size(); ++i){
        totalMarks += marks[i];
    }
    double averageMark = totalMarks / marks.size();
    averageMark = static_cast<int>(averageMark * 100 + 0.5) / 100.0;
    return averageMark;
}

double Student::calculateStudentGPA(const std::vector<Student>& students, const char* name) const{
    for(std::size_t i = 0; i < students.size(); ++i){
        if (std::strcmp(students[i].getName(), name) == 0) {
            return calculateGPA(students[i].getMarks());
        }
    }
    return 0.0;
} 

int main(){
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<Student> students;

    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        std::cout << "Enter name for student " << i + 1 << ": ";
        std::cin >> name;

        int facultyNumber = std::rand();

        Student student(name.c_str(), facultyNumber);

        std::vector<double> marks;
        int numMarks;
        std::cout << "Enter the number of marks for " << name << ": ";
        std::cin >> numMarks;

        for(int j = 0; j < numMarks; ++j){
            double mark;
            std::cout << "Enter mark " << j + 1 << ": ";
            std::cin >> mark;
            marks.push_back(mark);
        }

        student.setMarks(marks);

        students.push_back(student);
    }

    for(std::size_t i = 0; i < students.size(); ++i){
        const Student& student = students[i];
        double gpa = student.calculateGPA(student.getMarks());
        std::cout << "Student: " << student.getName() << ", Faculty Number: " << student.getFacultyNumber() << ", GPA: " << gpa << std::endl;
    }
    return 0;
}
