/*Task 1:
We need to store anonymous data about programmers’ salary and position. 
==first part== 
Create a binary file called salary.bin. 
Until there is input from the console write the data to the file. 

==second part==
Then read the file and calculate the average salary of a position including a word read from the console. 
Round the result to 2 decimal places.  

Example: 
 
Input:
Java Developer 4200 
C++ Developer 5000 
JavaScript Developer 1000 
Junior C++ Developer 1500 
Software Engineer 3400 
Game Developer (C++) 4000 

//word to match
C++ 

Output:  
Average C++ salary is: 3500*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


struct Programmer{
    std::string position;
    double salary;
};

int main(){

    std::ofstream file("salary.bin", std::ios::binary);//std::ios::binary indicates that the file should be opened in binary mode
    if(!file){
        std::cerr << "Failed to create the file." << std::endl;
        return 1;
    }

    while(true){
        Programmer programmer;
        std::cout << "Enter the programmer's position (or press enter to quit): ";
        std::getline(std::cin, programmer.position);

        if(programmer.position.empty())
            break;

        std::cout << "Enter the programmer's salary: ";
        std::cin >> programmer.salary;
        std::cin.ignore(); 

        file.write(reinterpret_cast<char*>(&programmer), sizeof(programmer));

        std::cout << "Data has been written to the file." << std::endl;
    }

    file.close();


    std::ifstream readFile("salary.bin", std::ios::binary);
    if (!readFile) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string wordToMatch;
    std::cout << "Enter a word to match positions (case-sensitive): ";
    //std::cin >> wordToMatch;
    std::getline(std::cin, wordToMatch);

    double totalSalary = 0.0;
    int counter = 0;
    Programmer readProgrammer;

    while (readFile.read(reinterpret_cast<char*>(&readProgrammer), sizeof(readProgrammer))) {
        if (readProgrammer.position == wordToMatch) {
            totalSalary += readProgrammer.salary;
            counter++;
        }
    }

    // while (readFile.read(reinterpret_cast<char*>(&readProgrammer), sizeof(readProgrammer))) {
    // // convert to a C-style string
    // const char* positionStr = readProgrammer.position.c_str();
    
    // // checking: the position contains the matching word
    // if (std::string(positionStr).find(wordToMatch) != std::string::npos) {
    //     totalSalary += readProgrammer.salary;
    //     counter++;
    // }
}
    

    double averageSalary = (counter != 0) ? (totalSalary / counter) : 0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average salary for positions matching \"" << wordToMatch << "\": $" << averageSalary << std::endl;


    readFile.close();

    return 0;
}


