#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    // Data members
    string brand;
    int mileage;
    string engine;
    void print()
    {
        cout << "The Print Function Defines Inside Car Class" << endl;
        cout << "Complany Name Is " << this->brand << endl;
    }
};
int main()
{
    // helps us create a structure so that we dont have to repeat our code everysingle time for each user
    //: P
    // more like a blueprint for a set of data or collection
    // similar to schema in databases
    // platform independent envirornment
    // mostly same in all the other languages
    // class =>> creating structure for an object
    // object =>> collection of data structure for a single entity
    // In object-oriented programming (OOP), a class is a blueprint or template used to create objects. It defines the common structure (attributes) and behavior (methods) that all objects of a specific type will share.

    Car c1;
    c1.brand = "Toyota";
    c1.engine = "V8";
    c1.mileage = 0;

    cout << c1.brand << endl;
    cout << c1.engine << endl;

    Car c2 = {
        brand : "Lmbrgmbr",
        mileage : 15,
        engine : "V10"
    };
    cout << c2.brand << endl;
    cout << c2.engine << endl;
    cout << "HELLO OOPS!" << endl;
    return 0;
    // static void main
}
