// Inheritance is a mechanism in which one class inherits the properties of another class. It is a mechanism to reuse code and to create a new class that is similar to the existing class
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal can eat." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // Inherited from Animal class
    myDog.bark(); // Defined in Dog class

    return 0;
}