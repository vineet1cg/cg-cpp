/*
    Modern C++ Inheritance Demonstration
    ------------------------------------
    Concepts Covered:
    - Encapsulation
    - Abstraction
    - Inheritance
    - Polymorphism (runtime)
    - Constructor chaining
    - Virtual destructors
    - Function overriding vs function hiding
    - Base class method invocation
    - Const correctness
*/

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

//////////////////////////////////////////////////////////////
//                      ABSTRACTION
//////////////////////////////////////////////////////////////

/*
    Base Class: Animal

    This class represents a general animal.
    It provides a common interface for all derived classes.
*/

class Animal
{
    //////////////////////////////////////////////////////////////
    //                      ENCAPSULATION
    //////////////////////////////////////////////////////////////

private:
    // Private data members (cannot be accessed directly)
    string name_;
    int age_;

protected:
    // Accessible inside derived classes
    string species_;

public:
    //////////////////////////////////////////////////////////////
    //                      CONSTRUCTOR
    //////////////////////////////////////////////////////////////

    /*
        Constructor chaining begins here.
        When a derived class object is created,
        this constructor executes FIRST.
    */
    Animal(const string &name, int age, const string &species)
        : name_(name), age_(age), species_(species)
    {
        cout << "Animal constructor called for " << name_ << endl;
    }

    //////////////////////////////////////////////////////////////
    //                  VIRTUAL DESTRUCTOR
    //////////////////////////////////////////////////////////////

    /*
        Virtual destructor is CRITICAL for polymorphism.
        If we delete a derived object using a base pointer,
        the derived destructor must execute first.

        Destruction order:
        1) Derived destructor
        2) Base destructor
    */
    virtual ~Animal()
    {
        cout << "Animal destructor called for " << name_ << endl;
    }

    //////////////////////////////////////////////////////////////
    //                      GETTERS / SETTERS
    //////////////////////////////////////////////////////////////

    string getName() const { return name_; }
    int getAge() const { return age_; }
    string getSpecies() const { return species_; }

    void setAge(int age)
    {
        if (age >= 0)
            age_ = age;
    }

    //////////////////////////////////////////////////////////////
    //                      POLYMORPHIC INTERFACE
    //////////////////////////////////////////////////////////////

    // Virtual function enables runtime polymorphism
    virtual void speak() const
    {
        cout << "Animal makes a generic sound." << endl;
    }

    virtual void move() const
    {
        cout << "Animal moves in some way." << endl;
    }

    //////////////////////////////////////////////////////////////
    //                      NON-VIRTUAL METHOD
    //////////////////////////////////////////////////////////////

    /*
        This method is NOT virtual.
        It demonstrates normal method behavior.
    */
    void info() const
    {
        cout << "Name: " << name_
             << ", Age: " << age_
             << ", Species: " << species_
             << endl;
    }
};

//////////////////////////////////////////////////////////////
//                      INHERITANCE
//////////////////////////////////////////////////////////////

/*
    Derived Class #1 : Dog
*/

class Dog : public Animal
{
private:
    string breed_;

public:
    //////////////////////////////////////////////////////////////
    //                  CONSTRUCTOR CHAINING
    //////////////////////////////////////////////////////////////

    /*
        Execution order when creating Dog:

        1) Animal constructor
        2) Dog constructor
    */
    Dog(const string &name, int age, const string &breed)
        : Animal(name, age, "Dog"), breed_(breed)
    {
        cout << "Dog constructor called for " << getName() << endl;
    }

    //////////////////////////////////////////////////////////////
    //                      DESTRUCTOR
    //////////////////////////////////////////////////////////////

    /*
        Destruction order:

        1) Dog destructor
        2) Animal destructor
    */
    ~Dog() override
    {
        cout << "Dog destructor called for " << getName() << endl;
    }

    //////////////////////////////////////////////////////////////
    //                  FUNCTION OVERRIDING
    //////////////////////////////////////////////////////////////

    void speak() const override
    {
        cout << getName() << " says: Woof!" << endl;
    }

    void move() const override
    {
        cout << getName() << " runs on four legs." << endl;
    }

    //////////////////////////////////////////////////////////////
    //          CALLING BASE CLASS METHOD EXPLICITLY
    //////////////////////////////////////////////////////////////

    void info() const
    {
        // Explicitly calling base class version
        Animal::info();
        cout << "Breed: " << breed_ << endl;
    }

    //////////////////////////////////////////////////////////////
    //          FUNCTION HIDING DEMONSTRATION
    //////////////////////////////////////////////////////////////

    /*
        If Animal had another method named fetch(int),
        and we define fetch() here,
        the base version would be hidden.
    */
    void fetch() const
    {
        cout << getName() << " is fetching the ball!" << endl;
    }
};

//////////////////////////////////////////////////////////////
//                      INHERITANCE
//////////////////////////////////////////////////////////////

/*
    Derived Class #2 : Bird
*/

class Bird : public Animal
{
private:
    bool canFly_;

public:
    Bird(const string &name, int age, bool canFly)
        : Animal(name, age, "Bird"), canFly_(canFly)
    {
        cout << "Bird constructor called for " << getName() << endl;
    }

    ~Bird() override
    {
        cout << "Bird destructor called for " << getName() << endl;
    }

    //////////////////////////////////////////////////////////////
    //                  FUNCTION OVERRIDING
    //////////////////////////////////////////////////////////////

    void speak() const override
    {
        cout << getName() << " says: Tweet!" << endl;
    }

    void move() const override
    {
        if (canFly_)
            cout << getName() << " flies in the sky." << endl;
        else
            cout << getName() << " walks on the ground." << endl;
    }
};

//////////////////////////////////////////////////////////////
//                      POLYMORPHISM
//////////////////////////////////////////////////////////////

int main()
{
    /*
        We use smart pointers (unique_ptr)
        instead of raw pointers.

        Why?
        - Automatic memory management
        - No manual delete
        - No memory leaks
    */

    vector<unique_ptr<Animal>> animals;

    animals.push_back(make_unique<Dog>("Buddy", 3, "Golden Retriever"));
    animals.push_back(make_unique<Bird>("Kiwi", 2, true));

    cout << "\n===== Runtime Polymorphism Demonstration =====\n"
         << endl;

    /*
        Even though animals is a container of
        Animal pointers, the overridden
        functions in Dog and Bird are called.

        This is RUNTIME POLYMORPHISM.
    */

    for (const auto &animal : animals)
    {
        animal->info();  // Not virtual (compile-time binding)
        animal->speak(); // Virtual (runtime binding)
        animal->move();  // Virtual (runtime binding)
        cout << "----------------------------------" << endl;
    }

    /*
        When main ends:

        - vector is destroyed
        - unique_ptr deletes objects
        - Derived destructors run
        - Base destructor runs

        Because destructor is virtual,
        correct cleanup happens.
    */

    return 0;
}