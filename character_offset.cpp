/*
Name: Shane Davis
Class: CIS 1202 - Section 5T1
Date: 08/03/2025
Assignment: Programming Assignment #14 - Character Offset
*/

#include <iostream>
#include <stdexcept>
using namespace std;


class invalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character: must be A-Z or a-z.";
    }
};

class invalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid range: resulting character is outside A-Z or a-z.";
    }
};


char character(char start, int offset) {
    if (!isalpha(start)) {
        throw invalidCharacterException();
    }

    char result = start + offset;

    
    if (islower(start) && !islower(result)) {
        throw invalidRangeException();
    }
    else if (isupper(start) && !isupper(result)) {
        throw invalidRangeException();
    }

    return result;
}


int main() {
    try {
        cout << "Result: " << character('a', 1) << endl;   
        cout << "Result: " << character('Z', -1) << endl;  
        cout << "Result: " << character('b', -2) << endl;  
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "Result: " << character('1', 5) << endl;   
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}