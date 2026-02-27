#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    // Data members (attributes of the class)
    string name;
    int age;
    char section;
    /*
        Constructor
        - A constructor is a special member function that is automatically
          called when an object of the class is created.
        - It has the same name as the class.
        - It does NOT have a return type (not even void).
        - "this->" is used to refer to the current object's data members
          when parameter names are the same as member variable names.
    */
    Student(string name, int a, char s)
    {
        this->name = name; // Assign parameter 'name' to object's 'name'
        age = a;
        section = s;
    }

    /*
        Destructor
        - A destructor is automatically called when an object goes out of scope.
        - It is used to clean up resources if needed.
        - It has the same name as the class, preceded by '~'.
        - It does NOT take parameters and does NOT return anything.
    */
    ~Student()
    {
        cout << "Destructor called for " << this->name << endl;
    }
    // Member function to print student data
    void printData()
    {
        cout << "NAME : " << this->name << endl;
        cout << "AGE : " << this->age << endl;
        cout << "SECTION : " << this->section << endl;
    }
};

// Function demonstrating object creation inside a function
void createObj()
{
    /*
        Objects created inside a function are local to that function.
        When the function ends, the object goes out of scope and its
        destructor is automatically called.
    */
    Student func("Used By Function", 21, 'B');
    func.printData();
}

int main()
{
    // Creating objects of the Student class
    Student student1("John Doe", 20, 'A');
    Student Bhondu("Rishab", 18, 'B');

    student1.printData();
    Bhondu.printData();

    createObj();

    /*
        IMPORTANT NOTE ABOUT MEMORY IN C++:

        C++ does NOT have an automatic garbage collector like Java or C#.

        - Objects created normally (like above) are automatically destroyed
          when they go out of scope (stack memory).
        - If objects are created using 'new', they must be manually deleted
          using 'delete' to avoid memory leaks.

        When:
        - createObj() finishes → 'func' is destroyed.
        - main() finishes → 'student1' and 'Bhondu' are destroyed.
    */
    return 0;
}