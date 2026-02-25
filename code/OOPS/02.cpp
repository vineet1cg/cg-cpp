#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    //declaration of values
    string name;
    int age;
    char section;

    // Constructor (Does Not Have Any Return Type Cause It Doesnt Return 🥀 );
    Student(string n, int a, char s)
    {
        name = n;
        age = a;
        section = s;
    }
    // function for the created object 
    void printData(){
        cout<< "NAME : "<<this->name <<endl;
        cout<< "AGE : "<<this->age  <<endl;
        cout << "SECTION : " << this->section << endl;
    }
};
int main()
{
    // Create an object of the class
    Student student1("John Doe", 20, 'A');
    Student Bhondu("Rishab",18,'B');
    student1.printData();
    Bhondu.printData();
    return 0;
}