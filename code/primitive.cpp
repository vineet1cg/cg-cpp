#include <iostream>
using namespace std;

int main() {
    // int: Used to store integer values.
    int number = 10;
    cout << "Int value: " << number << ", Size in bytes: " << sizeof(int) << endl;

    // float: Used to store floating-point numbers with single precision (7 decimal digits).
    float piFloat = 3.14f;
    cout << "Float value: " << piFloat << ", Size in bytes: " << sizeof(float) << endl;

    // double: Used to store floating-point numbers with double precision (15 decimal digits).
    double piDouble = 3.141592653589793;
    cout << "Double value: " << piDouble << ", Size in bytes: " << sizeof(double) << endl;

    // char: Used to store a single character enclosed in quotes.
    char initial = 'A';
    cout << "Char value: " << initial << ", Size in bytes: " << sizeof(char) << endl;

    // bool: Used to store boolean values (true or false).
    bool isStudent = true;
    cout << "Bool value: " << (isStudent ? "true" : "false") << ", Size in bytes: " << sizeof(bool) << endl;

    // short: Used to store short integer values.
    short smallNumber = 100;
    cout << "Short value: " << smallNumber << ", Size in bytes: " << sizeof(short) << endl;

    // long: Used to store long integer values.
    long largeNumber = 123456789L;
    cout << "Long value: " << largeNumber << ", Size in bytes: " << sizeof(long) << endl;

    // long long: Used to store very large integer values.
    long long veryLargeNumber = 123456789012345LL;
    cout << "Long Long value: " << veryLargeNumber << ", Size in bytes: " << sizeof(long long) << endl;

    return 0;
}