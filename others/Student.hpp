#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <cstring>
#include <iostream>
#include <vector>
#include <cstdlib>// For rand() function

/*Task 2: 
Create a class Student. 
The student should have a name (character string of arbitrary length), 
                            faculty number which has to be generated randomly and 
                            array of marks with arbitrary length. 

Create set and get methods of your choice. 

After that create a function which gets an array of Students (can be a vector too) and a name and output the GPA of the student.*/

class Student{
private:
    char* name;
    int facultyNumber;
    std::vector<double> marks;
    
    void cleanup();
    void copy(const Student& other);

public:

    Student(const char* _name = "<anonymous>", int _fn = 0);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();
    
    int generateFacultyNumber();

    char* getName()const;
    int getFacultyNumber()const;
    std::vector<double> getMarks()const;

    void setName(const char* _name);
    void setFAcultyNumber(int _facultyNumber);
    void setMarks(const std::vector<double>& studentMarks);

    double calculateGPA(const std::vector<double>& marks) const;
    double calculateStudentGPA(const std::vector<Student>& students, const char* name)const;
    void print()const;

};

#endif
