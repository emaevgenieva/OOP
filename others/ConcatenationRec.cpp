/*Task 3: Write a recursive function which gets a string and a number n and a string or char which will be
used as a separator. The output should be the input string concatenated N-times with itself separated by
the separator.  
Example:  
string: inensia 
n: 3 
separator: &lt;3 
Output:  
Inensia&lt;3inensia&lt;3inensia*/


#include <iostream>
#include <string>
using std::cin;
using std::cout;

std::string concatenateNTimes(const std::string str, int n, std::string separator){
    if(n == 1){
        return str;
    }
    return str + separator + concatenateNTimes(str, n - 1, separator);
}

int main(){
    // std::string str = "Inensia";
    // int n = 3;
    // std::string separator = "<3";

    std::string str;
    cout<<"Enter a string: ";
    std::getline(cin, str);

    int n;
    cout<<"Enter a number: ";
    cin >> n;

    cin.ignore();
    std::string separator;
    cout <<"Enter a separator: ";
    std::getline(cin, separator);

    std::string result = concatenateNTimes(str,n,separator);
    cout << "The result is: " << result<< "\n";
}