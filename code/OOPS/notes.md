# OOPS (Object-Oriented Programming System) - Complete Exam Notes

---

## Table of Contents
1. [Introduction to OOPS](#1-introduction-to-oops)
2. [Classes and Objects](#2-classes-and-objects)
3. [Encapsulation](#3-encapsulation)
4. [Abstraction](#4-abstraction)
5. [Inheritance](#5-inheritance)
6. [Polymorphism](#6-polymorphism)
7. [Constructors and Destructors](#7-constructors-and-destructors)
8. [Access Specifiers](#8-access-specifiers)
9. [Virtual Functions & Virtual Destructors](#9-virtual-functions--virtual-destructors)
 Ch10. [Constructoraining](#10-constructor-chaining)
11. [Important C++ Notes](#11-important-c-notes)

---

## 1. INTRODUCTION TO OOPS

### What is OOPS?
- **OOPS** = Object-Oriented Programming System
- A programming paradigm based on the concept of **objects**
- **Class** = Blueprint/template for creating objects
- **Object** = Instance of a class (collection of data for a single entity)
- Platform-independent
- Used to organize code into reusable structures

### Key Pillars of OOPS:
1. **Encapsulation** - Binding data and functions together
2. **Abstraction** - Hiding complex details, showing only essentials
3. **Inheritance** - Acquiring properties of one class into another
4. **Polymorphism** - One name, multiple forms

---

## 2. CLASSES AND OBJECTS

### Class Declaration
```cpp
class ClassName {
public:
    // Data members (attributes)
    string name;
    int age;
    
    // Member functions (methods)
    void print() {
        cout << "Hello";
    }
};
```

### Creating Objects
```cpp
ClassName obj1;                    // Stack allocation
ClassName obj2 = {                 // Brace-enclosed initialization
    name: "John",
    age: 20
};
```

### Accessing Members
```cpp
obj1.name = "Alice";
obj1.print();
```

### Using `this` Pointer
- `this` points to the current object
- Used to distinguish between member variables and parameters with same name
```cpp
class Car {
public:
    string brand;
    void setBrand(string brand) {
        this->brand = brand;  // this->brand = object's brand
    }
};
```

---

## 3. ENCAPSULATION

### Definition
- **Wrapping data (variables) and functions (methods) together in a single unit (class)**
- Data is protected inside the class
- Access provided through controlled interfaces (getters/setters)

### How to Achieve
1. Declare class variables as **private**
2. Provide **public getter and setter** methods

### Example:
```cpp
class BankAccount {
private:
    double balance;  // Hidden from outside
    
public:
    void setBalance(double b) {
        if(b >= 0) balance = b;  // Validation
    }
    double getBalance() {
        return balance;
    }
};
```

### Benefits:
- Data hiding (security)
- Code reusability
- Modular code
- Flexibility

---

## 4. ABSTRACTION

### Definition
- **Hiding complex implementation details and showing only the necessary features**
- Focus on "what it does" not "how it does"

### How to Achieve
- Using **abstract classes** (classes with pure virtual functions)
- Using **interfaces**
- Using **header files**

### Example:
```cpp
class Animal {
public:
    virtual void speak() = 0;  // Pure virtual function
    // No implementation here - just declaration
};
```

### Real-world Example:
- You press brake pedal without knowing internal mechanism
- You make call without knowing how network works

### Difference: Encapsulation vs Abstraction
| Encapsulation | Abstraction |
|---------------|-------------|
| Data wrapping | Hiding complexity |
| "How to achieve" | "What to achieve" |
| Private members + public methods | Interface + hidden implementation |

---

## 5. INHERITANCE

### Definition
- **Mechanism where one class acquires the properties (attributes and methods) of another class**
- Enables code reusability
- Establishes parent-child relationship

### Syntax:
```cpp
class ParentClass {
public:
    void parentMethod() { }
};

class ChildClass : public ParentClass {
public:
    void childMethod() { }
};
```

### Types of Inheritance:
1. **Single Inheritance** - One parent, one child
2. **Multiple Inheritance** - Two parents, one child
3. **Multilevel Inheritance** - Grandparent → Parent → Child
4. **Hierarchical Inheritance** - One parent, multiple children
5. **Hybrid Inheritance** - Combination of above types

### Access Specifiers with Inheritance:
| Inheritance Type | private members | protected members | public members |
|------------------|-----------------|------------------|----------------|
| `public`         | Not inherited   | Protected        | Public         |
| `protected`      | Not inherited   | Protected        | Protected      |
| `private`        | Not inherited   | Private          | Private        |

### Example - Single Inheritance:
```cpp
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
    myDog.eat();   // Inherited from Animal
    myDog.bark(); // Own method
    return 0;
}
```

### Calling Base Class Method Explicitly:
```cpp
void info() const {
    Animal::info();  // Calls base class version
    cout << "Breed: " << breed_ << endl;
}
```

---

## 6. POLYMORPHISM

### Definition
- **"Poly" = Many, "Morph" = Forms**
- One interface, multiple implementations
- Ability to take multiple forms

### Types:
1. **Compile-time (Static) Polymorphism**
   - Function Overloading
   - Operator Overloading
   
2. **Runtime (Dynamic) Polymorphism**
   - Function Overriding (using virtual functions)

### Function Overloading (Compile-time)
- Same function name, different parameters
```cpp
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};
```

### Function Overriding (Runtime)
- Derived class provides different implementation of base class method
- Requires **virtual** keyword in base class
```cpp
class Animal {
public:
    virtual void speak() const {
        cout << "Animal makes a generic sound." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof!" << endl;
    }
};
```

### Runtime Polymorphism with Pointers:
```cpp
vector<unique_ptr<Animal>> animals;
animals.push_back(make_unique<Dog>("Buddy", 3, "Golden Retriever"));
animals.push_back(make_unique<Bird>("Kiwi", 2, true));

for (const auto &animal : animals) {
    animal->speak();  // Calls appropriate derived class method
}
```

### Function Hiding:
- If base class has a method and derived class defines a method with same name (but different signature), base method is **hidden** (not overridden)

---

## 7. CONSTRUCTORS AND DESTRUCTORS

### Constructor
- **Special member function**
- **Same name as class**
- **No return type** (not even void)
- **Automatically called** when object is created
- Used to initialize objects

#### Types of Constructors:
1. **Default Constructor** - No parameters
2. **Parameterized Constructor** - With parameters
3. **Copy Constructor** - Copies one object to another

#### Parameterized Constructor Example:
```cpp
class Student {
public:
    string name;
    int age;
    char section;
    
    Student(string name, int a, char s) {
        this->name = name;
        age = a;
        section = s;
    }
};

Student student1("John Doe", 20, 'A');
```

### Destructor
- **Special member function**
- **Same name as class with ~ prefix**
- **No return type, no parameters**
- **Automatically called** when object goes out of scope
- Used for cleanup (releasing resources)

```cpp
class Student {
public:
    string name;
    
    ~Student() {
        cout << "Destructor called for " << this->name << endl;
    }
};
```

### Constructor vs Destructor
| Constructor | Destructor |
|-------------|------------|
| Same name as class | ~ClassName |
| Called when object is created | Called when object is destroyed |
| Can be overloaded | Cannot be overloaded |
| Initializes object | Cleans up resources |

### Execution Order:
**Creation:** Base Constructor → Derived Constructor
**Destruction:** Derived Destructor → Base Destructor

---

## 8. ACCESS SPECIFIERS

### Types:
1. **private**
   - Accessible only within the class
   - Not accessible in derived classes
   - Not accessible by objects
   
2. **protected**
   - Accessible within the class
   - Accessible in derived classes
   - Not accessible by objects
   
3. **public**
   - Accessible everywhere
   - Accessible within class
   - Accessible in derived classes
   - Accessible by objects

### Quick Reference:
```cpp
class MyClass {
private:     // Only MyClass
    int a;
    
protected:   // MyClass + Derived classes
    int b;
    
public:      // Everyone
    int c;
};
```

### Default Access Specifier:
- For **class**: private
- For **struct**: public

---

## 9. VIRTUAL FUNCTIONS & VIRTUAL DESTRUCTORS

### Virtual Functions
- Enables **runtime polymorphism**
- Use `virtual` keyword in base class
- Use `override` keyword in derived class (optional but recommended)
- Uses **vtable** (virtual table) for runtime binding

```cpp
class Base {
public:
    virtual void show() {
        cout << "Base show" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived show" << endl;
    }
};

Base* ptr = new Derived();
ptr->show();  // Calls Derived's show()
```

### Virtual Destructor
- **CRITICAL** for proper cleanup when deleting derived object through base pointer
- Without virtual destructor → only base destructor called (memory leak!)

```cpp
class Animal {
public:
    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }
};

class Dog : public Animal {
public:
    ~Dog() override {
        cout << "Dog destructor" << endl;
    }
};

Animal* ptr = new Dog();
delete ptr;
// Output: Dog destructor, then Animal destructor
```

### Pure Virtual Function
- Function with `= 0` syntax
- Makes class **abstract** (cannot instantiate)
- Derived classes MUST override

```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};
```

---

## 10. CONSTRUCTOR CHAINING

### Definition
- When derived class object is created, **base class constructor runs first**, then derived class constructor

### Execution Order:
```
1. Base class constructor
2. Derived class constructor
```

### Example:
```cpp
class Animal {
public:
    Animal(const string &name, int age, const string &species)
        : name_(name), age_(age), species_(species) {
        cout << "Animal constructor called for " << name_ << endl;
    }
    virtual ~Animal() {
        cout << "Animal destructor called for " << name_ << endl;
    }
};

class Dog : public Animal {
public:
    Dog(const string &name, int age, const string &breed)
        : Animal(name, age, "Dog"), breed_(breed) {
        cout << "Dog constructor called for " << getName() << endl;
    }
    ~Dog() override {
        cout << "Dog destructor called for " << getName() << endl;
    }
};
```

### Output when creating Dog:
```
Animal constructor called for Buddy
Dog constructor called for Buddy
```

### Output when Dog is destroyed:
```
Dog destructor called for Buddy
Animal destructor called for Buddy
```

---

## 11. IMPORTANT C++ NOTES

### Memory Management
- **NO automatic garbage collector** like Java/C#
- Objects created on **stack** are automatically destroyed when out of scope
- Objects created with `new` must be manually deleted with `delete`

### Smart Pointers (Modern C++)
```cpp
#include <memory>

vector<unique_ptr<Animal>> animals;
animals.push_back(make_unique<Dog>("Buddy", 3, "Golden Retriever"));
// Automatically deleted when vector is destroyed
```

### `const` Correctness
- `const` methods cannot modify member variables
- `const` parameters cannot be modified
```cpp
class Example {
public:
    void display() const {  // Cannot modify any member
        // this->x = 5;  // ERROR!
    }
};
```

### Initialization List
```cpp
class Animal {
private:
    string name_;
    int age_;
public:
    Animal(const string &name, int age) 
        : name_(name), age_(age) {  // Initialization list
        // Can also do assignments here
    }
};
```

### String Class
```cpp
#include <string>
string s1 = "Hello";
string s2 = "World";
cout << s1 + " " + s2;  // Concatenation
```

---

## QUICK EXAM REVISION CHEAT SHEET

### OOPS 4 Pillars:
1. **Encapsulation** - Data + Methods in one unit
2. **Abstraction** - Hiding details
3. **Inheritance** - Reuse code
4. **Polymorphism** - Many forms

### Access Specifiers:
- **private** → Class only
- **protected** → Class + Derived
- **public** → Everywhere

### Constructor vs Destructor:
- Constructor: Same name as class, no return, called on creation
- Destructor: ~ClassName, no return, called on destruction

### Virtual Function:
- `virtual` in base class → enables runtime polymorphism
- `override` in derived class → indicates overriding
- Virtual destructor → ensures proper cleanup

### Inheritance Types:
- Single: One parent
- Multiple: Two parents
- Multilevel: Grandparent → Parent → Child

### Execution Order:
**Object Creation:** Base Constructor → Derived Constructor
**Object Destruction:** Derived Destructor → Base Destructor

### Key Keywords:
- `this` - Points to current object
- `virtual` - Enables polymorphism
- `override` - Explicitly override base method
- `new` / `delete` - Manual memory allocation/deallocation
- `unique_ptr` - Smart pointer (auto cleanup)

---

## COMMON EXAM QUESTIONS & ANSWERS

### Q1: What is the difference between class and object?
**A:** Class is a blueprint/template; Object is an instance of class.

### Q2: What is the difference between encapsulation and abstraction?
**A:** Encapsulation is data hiding (wrapping), Abstraction is implementation hiding.

### Q3: Why use virtual destructor?
**A:** To ensure derived class destructor is called when deleting through base pointer.

### Q4: What is constructor chaining?
**A:** Base class constructor executes before derived class constructor.

### Q5: Can destructor be overloaded?
**A:** No, destructors cannot be overloaded (only one per class).

### Q6: What is runtime polymorphism?
**A:** Function overriding using virtual functions - actual function called determined at runtime.

### Q7: What is the difference between function overloading and overriding?
**A:** Overloading = Same name, different parameters (compile-time); Overriding = Same signature, different implementation (runtime).

### Q8: What is pure virtual function?
**A:** Virtual function with `= 0`, makes class abstract, must be overridden by derived classes.

---

*Last Updated: Based on your OOPS C++ code files*
*Practice all code examples for exam success!*
