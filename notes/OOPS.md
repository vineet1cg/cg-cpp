# Complete C++ Object-Oriented Programming (OOPS) Guide

This document covers all OOPS concepts in C++ from basics to advanced topics with examples and important notes.

---

## Table of Contents

1. [Classes and Objects](#1-classes-and-objects)
2. [Access Specifiers](#2-access-specifiers)
3. [Constructors](#3-constructors)
4. [Destructors](#4-destructors)
5. [this Pointer](#5-this-pointer)
6. [Encapsulation](#6-encapsulation)
7. [Abstraction](#7-abstraction)
8. [Inheritance](#8-inheritance)
9. [Polymorphism](#9-polymorphism)
10. [Friend Functions and Classes](#10-friend-functions-and-classes)
11. [Static Members](#11-static-members)
12. [const Correctness](#12-const-correctness)
13. [Operator Overloading](#13-operator-overloading)
14. [Copy and Move Semantics](#14-copy-and-move-semantics)
15. [Virtual Functions](#15-virtual-functions)
16. [Diamond Problem](#16-diamond-problem)
17. [Templates in OOP](#17-templates-in-oop)
18. [Smart Pointers](#18-smart-pointers)
19. [Rule of Three/Five/Zero](#19-rule-of-threefivezero)
20. [Nested Classes](#20-nested-classes)
21. [Type Casting](#21-type-casting)

---

## 1. Classes and Objects

A class is a blueprint for creating objects. It defines attributes (data members) and behaviors (member functions).

### Syntax

```cpp
class ClassName {
public:
    // data members
    // member functions
};
```

### Example

```cpp
#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand;
    int mileage;
    string engine;
    
    void print() {
        cout << "Brand: " << brand << endl;
    }
};

int main() {
    Car c1;
    c1.brand = "Toyota";
    c1.mileage = 0;
    c1.engine = "V8";
    c1.print();
    
    // Designated initializer (C++11)
    Car c2 = {"BMW", 10, "V12"};
    c2.print();
    
    return 0;
}
```

### Key Points

- Class is a blueprint; Object is an instance of a class
- Objects occupy memory; Classes do not
- Multiple objects can be created from a single class

---

## 2. Access Specifiers

Access specifiers control the visibility/access of class members.

| Specifier | Same Class | Derived Class | Outside Class |
|-----------|------------|---------------|---------------|
| `private` | ✓ | ✗ | ✗ |
| `protected` | ✓ | ✓ | ✗ |
| `public` | ✓ | ✓ | ✓ |

### Example

```cpp
class Base {
private:
    int privateVar = 1;
protected:
    int protectedVar = 2;
public:
    int publicVar = 3;
};

class Derived : public Base {
    void access() {
        // privateVar - NOT accessible
        protectedVar = 10;  // ✓ Accessible
        publicVar = 20;      // ✓ Accessible
    }
};

int main() {
    Base b;
    // b.privateVar - NOT accessible
    // b.protectedVar - NOT accessible
    b.publicVar = 30;  // ✓ Accessible
    return 0;
}
```

### Things to Remember

- Default access for class members is `private`
- Default access for struct members is `public`
- Use `private` for data hiding, `protected` for inheritance, `public` for interface

---

## 3. Constructors

A constructor is a special member function called when an object is created.

### Types of Constructors

#### 3.1 Default Constructor

```cpp
class Student {
public:
    string name;
    int age;
    
    // Default constructor (no parameters)
    Student() {
        name = "Unknown";
        age = 0;
        cout << "Default constructor called" << endl;
    }
};

int main() {
    Student s1;  // Calls default constructor
    return 0;
}
```

#### 3.2 Parameterized Constructor

```cpp
class Student {
public:
    string name;
    int age;
    
    Student(string n, int a) {
        name = n;
        age = a;
    }
    
    // OR use initializer list (preferred)
    Student(string n, int a) : name(n), age(a) {}
};

int main() {
    Student s1("John", 20);
    return 0;
}
```

#### 3.3 Copy Constructor

```cpp
class Student {
public:
    string name;
    int age;
    
    Student(string n, int a) : name(n), age(a) {}
    
    // Copy constructor
    Student(const Student& other) : name(other.name), age(other.age) {
        cout << "Copy constructor called" << endl;
    }
};

int main() {
    Student s1("John", 20);
    Student s2 = s1;  // Copy constructor called
    Student s3(s1);   // Copy constructor called
    return 0;
}
```

#### 3.4 Move Constructor (C++11)

```cpp
class Buffer {
public:
    int* data;
    size_t size;
    
    Buffer(size_t s) : size(s) {
        data = new int[s];
    }
    
    // Move constructor
    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
    
    ~Buffer() { delete[] data; }
};

int main() {
    Buffer b1(100);
    Buffer b2 = std::move(b1);  // Move constructor
    return 0;
}
```

#### 3.5 Constructor Initializer List

```cpp
class Person {
private:
    const string name;      // Must be initialized in initializer list
    int& ageRef;           // Must be initialized in initializer list
public:
    Person(string n, int& a) : name(n), ageRef(a) {}
};
```

### Things to Remember

- Constructor name = class name
- No return type (not even void)
- Can be overloaded
- If no constructor defined, compiler provides default constructor
- Initializer list is more efficient than assignment in body

---

## 4. Destructors

A destructor is called when an object goes out of scope or is deleted.

```cpp
class Student {
public:
    string name;
    
    Student(string n) : name(n) {
        cout << "Constructor for " << name << endl;
    }
    
    ~Student() {
        cout << "Destructor for " << name << endl;
    }
};

void func() {
    Student s("Local");
}

int main() {
    Student s1("Global");
    func();
    cout << "After func()" << endl;
    return 0;
}

// Output:
// Constructor for Global
// Constructor for Local
// Destructor for Local
// After func()
// Destructor for Global
```

### Key Points

- Name: `~ClassName`
- No parameters, no return type
- Only one destructor per class
- Virtual destructor needed for polymorphic base classes
- Called in reverse order of construction

---

## 5. this Pointer

`this` is a pointer that points to the current object.

```cpp
class Box {
private:
    int length;
    int breadth;
    int height;
    
public:
    Box(int length, int breadth, int height) {
        this->length = length;    // Distinguish member from parameter
        this->breadth = breadth;
        this->height = height;
    }
    
    Box* getThis() {
        return this;
    }
    
    void compare(Box* other) {
        if (this == other) {
            cout << "Same object" << endl;
        }
    }
};
```

### Things to Remember

- `this` is a constant pointer (`ClassName* const`)
- Cannot modify `this` to point to another object
- Used to differentiate between member variables and parameters with same name

---

## 6. Encapsulation

Bundling data and methods that operate on that data into a single unit (class).

```cpp
class BankAccount {
private:
    double balance;  // Hidden from outside
    
public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }
    
    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount acc;
    acc.deposit(1000);
    acc.withdraw(500);
    cout << acc.getBalance() << endl;
    // acc.balance = 1000000;  // ERROR - private
    return 0;
}
```

### Benefits

- Data hiding (security)
- Improved maintainability
- Code reusability
- Abstraction of implementation details

---

## 7. Abstraction

Showing only essential information, hiding implementation details.

```cpp
class Database {
private:
    // Hidden implementation details
    void connectToServer();
    void encryptData();
    void compressData();
    
public:
    // Public interface
    void save(string data) {
        connectToServer();
        encryptData();
        compressData();
        // Save to database
    }
    
    string fetch(int id) {
        // Fetch and decrypt
    }
};

int main() {
    Database db;
    db.save("important data");  // User doesn't know how it's saved
    return 0;
}
```

### Ways to Achieve Abstraction

1. **Abstract classes** (pure virtual functions)
2. **Interfaces** (abstract classes with only pure virtual functions)
3. **Header files** (hiding implementation in .cpp)

---

## 8. Inheritance

Inheritance allows a class to inherit properties from another class.

### Types of Inheritance

#### 8.1 Single Inheritance

```cpp
class Animal {
public:
    void eat() { cout << "Eating..." << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Woof!" << endl; }
};

int main() {
    Dog d;
    d.eat();  // Inherited
    d.bark();
    return 0;
}
```

#### 8.2 Multilevel Inheritance

```cpp
class Animal { void eat(); };
class Mammal : public Animal { void walk(); };
class Dog : public Mammal { void bark(); };
```

#### 8.3 Hierarchical Inheritance

```cpp
class Animal { void eat(); };
class Dog : public Animal { void bark(); };
class Cat : public Animal { void meow(); };
```

#### 8.4 Multiple Inheritance

```cpp
class Writer { void write() { cout << "Writing..." << endl; } };
class Speaker { void speak() { cout << "Speaking..." << endl; } };

class Professor : public Writer, public Speaker {
public:
    void teach() { cout << "Teaching..." << endl; }
};
```

#### 8.5 Hybrid Inheritance

Combination of multiple types of inheritance.

### Access Modifiers in Inheritance

| Base Member | Public Derivation | Protected Derivation | Private Derivation |
|-------------|-------------------|---------------------|-------------------|
| `public` | `public` | `protected` | `private` |
| `protected` | `protected` | `protected` | `private` |
| `private` | Not accessible | Not accessible | Not accessible |

### Example

```cpp
class Base {
public:
    int pub = 1;
protected:
    int prot = 2;
private:
    int priv = 3;
};

class PublicDerived : public Base {
    void access() {
        pub = 10;    // ✓ public
        prot = 20;   // ✓ protected
        // priv = 30; // ✗ Not accessible
    }
};

class ProtectedDerived : protected Base {
    void access() {
        pub = 10;    // ✓ protected
        prot = 20;   // ✓ protected
    }
};

class PrivateDerived : private Base {
    void access() {
        pub = 10;    // ✓ private
        prot = 20;   // ✓ private
    }
};
```

### Constructor/Destructor Order

```cpp
class Base {
public:
    Base() { cout << "Base constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived constructor" << endl; }
    ~Derived() { cout << "Derived destructor" << endl; }
};

int main() {
    Derived d;
    return 0;
}

// Output:
// Base constructor
// Derived constructor
// Derived destructor
// Base destructor
```

---

## 9. Polymorphism

One name, many forms.

### 9.1 Compile-Time Polymorphism

#### Function Overloading

```cpp
class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};

int main() {
    Math m;
    cout << m.add(5, 3) << endl;       // 8
    cout << m.add(5.5, 3.3) << endl;   // 8.8
    cout << m.add(1, 2, 3) << endl;    // 6
    return 0;
}
```

#### Operator Overloading

See Section 13.

### 9.2 Runtime Polymorphism

Achieved through virtual functions (see Section 15).

---

## 10. Friend Functions and Classes

A friend function can access private/protected members of a class.

### 10.1 Friend Function

```cpp
class Box {
private:
    int length;
    
public:
    Box(int l) : length(l) {}
    
    // Declare friend function
    friend int getLength(Box);
};

// Define friend function (not a member)
int getLength(Box b) {
    return b.length;  // Can access private member
}

int main() {
    Box b(10);
    cout << getLength(b) << endl;  // 10
    return 0;
}
```

### 10.2 Friend Class

```cpp
class A {
private:
    int value = 100;
    
public:
    friend class B;  // B can access A's private members
};

class B {
public:
    void show(A& obj) {
        cout << obj.value << endl;  // Access private
    }
};

int main() {
    A a;
    B b;
    b.show(a);  // 100
    return 0;
}
```

### Things to Remember

- Friendship is NOT transitive (A's friend of B ≠ A's friend of C)
- Friendship is NOT inherited
- Use sparingly - breaks encapsulation

---

## 11. Static Members

Shared across all objects of a class.

### 11.1 Static Variable

```cpp
class Counter {
private:
    int count = 0;           // Each object has its own
    static int totalCount;   // Shared by all objects
    
public:
    Counter() { count++; totalCount++; }
    
    void display() {
        cout << "Count: " << count << endl;
        cout << "Total: " << totalCount << endl;
    }
};

// Initialize static member outside class
int Counter::totalCount = 0;

int main() {
    Counter c1, c2, c3;
    c1.display();
    return 0;
}
```

### 11.2 Static Function

```cpp
class Config {
private:
    static bool isInitialized;
    
public:
    static void init() {
        isInitialized = true;
        // Can only access static members
    }
    
    static bool isReady() {
        return isInitialized;
    }
};

bool Config::isInitialized = false;

int main() {
    Config::init();
    cout << Config::isReady() << endl;  // 1
    return 0;
}
```

### Things to Remember

- `static` members exist before any object is created
- Accessed via `ClassName::member` or object
- `static` functions can only access static members

---

## 12. const Correctness

### 12.1 const Member Functions

```cpp
class Box {
private:
    int length = 10;
    
public:
    int getLength() const {
        // length = 20;  // ERROR - cannot modify
        return length;
    }
};
```

### 12.2 const Objects

```cpp
class Box {
public:
    void display() { cout << "Display" << endl; }
    void show() const { cout << "Show const" << endl; }
};

int main() {
    Box b;
    const Box cb;  // const object
    
    b.display();   // ✓
    // cb.display(); // ERROR - non-const function
    cb.show();     // ✓ const function
    return 0;
}
```

### 12.3 const Parameters

```cpp
void print(const string& s) {
    // s = "modified";  // ERROR
    cout << s << endl;
}
```

---

## 13. Operator Overloading

Redefine operators for user-defined types.

### 13.1 Overloading + (Binary)

```cpp
class Complex {
private:
    double real, imag;
    
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;  // c1.operator+(c2)
    c3.display();  // 4 + 6i
    return 0;
}
```

### 13.2 Overloading << (Stream)

```cpp
class Point {
public:
    int x, y;
    
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    friend ostream& operator<<(ostream& out, const Point& p);
};

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    Point p(5, 10);
    cout << p << endl;  // (5, 10)
    return 0;
}
```

### 13.3 Overloading ++ (Unary)

```cpp
class Counter {
private:
    int value = 0;
    
public:
    Counter& operator++() {     // Prefix ++
        ++value;
        return *this;
    }
    
    Counter operator++(int) {  // Postfix ++
        Counter temp = *this;
        value++;
        return temp;
    }
    
    int get() const { return value; }
};

int main() {
    Counter c;
    ++c;
    cout << c.get() << endl;  // 1
    c++;
    cout << c.get() << endl;  // 2
    return 0;
}
```

### Things to Remember

- Cannot overload: `::`, `?:`, `.*`, `.`, `sizeof`
- At least one operand must be user-defined type
- Precedence and associativity cannot be changed

---

## 14. Copy and Move Semantics

### 14.1 Copy Constructor vs Copy Assignment

```cpp
class Buffer {
public:
    int* data;
    int size;
    
    Buffer(int s) : size(s) {
        data = new int[s];
    }
    
    // Copy constructor
    Buffer(const Buffer& other) : size(other.size) {
        data = new int[size];
        memcpy(data, other.data, size * sizeof(int));
    }
    
    // Copy assignment operator
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            memcpy(data, other.data, size * sizeof(int));
        }
        return *this;
    }
    
    ~Buffer() { delete[] data; }
};
```

### 14.2 Move Assignment

```cpp
class Buffer {
public:
    int* data;
    int size;
    
    Buffer(int s) : size(s) {
        data = new int[s];
    }
    
    // Move constructor
    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
    
    // Move assignment
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
    
    ~Buffer() { delete[] data; }
};
```

---

## 15. Virtual Functions

Enable runtime polymorphism.

### 15.1 Virtual Function

```cpp
class Animal {
public:
    virtual void speak() const {
        cout << "Generic sound" << endl;
    }
    
    virtual ~Animal() {}  // Virtual destructor
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* animal;
    
    Dog d;
    animal = &d;
    animal->speak();  // "Woof!"
    
    Cat c;
    animal = &c;
    animal->speak();  // "Meow!"
    
    return 0;
}
```

### 15.2 Pure Virtual Function

```cpp
class Shape {
public:
    virtual void draw() const = 0;  // Pure virtual
    virtual double area() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    void draw() const override {
        cout << "Drawing circle" << endl;
    }
    
    double area() const override {
        return 3.14 * radius * radius;
    }
};

int main() {
    // Shape s;  // ERROR - cannot instantiate abstract class
    Circle c(5);
    c.draw();
    cout << c.area() << endl;
    return 0;
}
```

### 15.3 Virtual Destructor

```cpp
class Base {
public:
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;
    // Output: Derived destructor, Base destructor
    return 0;
}
```

### Things to Remember

- Virtual functions enable runtime polymorphism
- `override` keyword ensures overriding (C++11)
- Virtual destructor prevents memory leaks
- Pure virtual makes class abstract

---

## 16. Diamond Problem

The diamond problem occurs in multiple inheritance when a class inherits from two classes that both inherit from a common base.

### Without Virtual Inheritance

```cpp
class Animal {
public:
    void eat() { cout << "Eating" << endl; }
};

class Mammal : public Animal {};
class Bird : public Animal {};

class Bat : public Mammal, public Bird {};  // Diamond problem!

int main() {
    Bat b;
    // b.eat();  // ERROR - ambiguous
    b.Mammal::eat();  // Need to specify
    b.Bird::eat();
    return 0;
}
```

### With Virtual Inheritance

```cpp
class Animal {
public:
    void eat() { cout << "Eating" << endl; }
};

class Mammal : virtual public Animal {};  // virtual
class Bird : virtual public Animal {};     // virtual

class Bat : public Mammal, public Bird {};  // Single eat()

int main() {
    Bat b;
    b.eat();  // Works! No ambiguity
    return 0;
}
```

### Virtual Inheritance Order

```cpp
class Animal {
public:
    Animal() { cout << "Animal constructor" << endl; }
};

class Mammal : virtual public Animal {
public:
    Mammal() { cout << "Mammal constructor" << endl; }
};

class Bird : virtual public Animal {
public:
    Bird() { cout << "Bird constructor" << endl; }
};

class Bat : public Mammal, public Bird {
public:
    Bat() { cout << "Bat constructor" << endl; }
};

int main() {
    Bat b;
    return 0;
}

// Output:
// Animal constructor  (only once!)
// Mammal constructor
// Bird constructor
// Bat constructor
```

---

## 17. Templates in OOP

### 17.1 Class Template

```cpp
template<typename T>
class Container {
private:
    T value;
public:
    Container(T v) : value(v) {}
    T getValue() const { return value; }
};

int main() {
    Container<int> intBox(42);
    Container<string> strBox("Hello");
    
    cout << intBox.getValue() << endl;
    cout << strBox.getValue() << endl;
    return 0;
}
```

### 17.2 Template with Multiple Parameters

```cpp
template<typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
};

int main() {
    Pair<int, string> p(1, "One");
    cout << p.getFirst() << " - " << p.getSecond() << endl;
    return 0;
}
```

---

## 18. Smart Pointers

Automatic memory management (C++11).

### 18.1 unique_ptr

```cpp
#include <memory>

class Resource {
public:
    Resource() { cout << "Acquired" << endl; }
    ~Resource() { cout << "Released" << endl; }
};

int main() {
    unique_ptr<Resource> ptr1 = make_unique<Resource>();
    
    // unique_ptr cannot be copied
    // unique_ptr<Resource> ptr2 = ptr1;  // ERROR
    
    // Can be moved
    unique_ptr<Resource> ptr2 = move(ptr1);
    // ptr1 is now null
    
    return 0;
}
```

### 18.2 shared_ptr

```cpp
#include <memory>

int main() {
    shared_ptr<int> ptr1 = make_shared<int>(42);
    shared_ptr<int> ptr2 = ptr1;  // Copy allowed
    
    cout << *ptr1 << " " << *ptr2 << endl;  // 42 42
    cout << ptr1.use_count() << endl;  // 2
    
    return 0;
}
```

### 18.3 weak_ptr

```cpp
#include <memory>

class Node {
public:
    int data;
    weak_ptr<Node> next;  // Avoids cyclic reference
    
    ~Node() { cout << "Node destroyed" << endl; }
};

int main() {
    auto n1 = make_shared<Node>();
    auto n2 = make_shared<Node>();
    
    n1->next = n2;
    n2->next = n1;
    
    // Without weak_ptr, memory would leak (cyclic reference)
    return 0;
}
```

---

## 19. Rule of Three/Five/Zero

### Rule of Three

If you define any of these, define all three:
1. Destructor
2. Copy constructor
3. Copy assignment operator

### Rule of Five

In C++11+, add:
4. Move constructor
5. Move assignment operator

### Rule of Zero

Prefer not defining any; use smart pointers.

```cpp
// Rule of Zero (recommended)
class Resource {
public:
    unique_ptr<int> data;
};

// Rule of Five
class Buffer {
private:
    int* data;
    size_t size;
    
public:
    Buffer(size_t s) : size(s), data(new int[s]) {}
    
    ~Buffer() { delete[] data; }
    
    // Copy constructor
    Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
        memcpy(data, other.data, size * sizeof(int));
    }
    
    // Copy assignment
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            memcpy(data, other.data, size * sizeof(int));
        }
        return *this;
    }
    
    // Move constructor
    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
    
    // Move assignment
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};
```

---

## 20. Nested Classes

A class defined within another class.

```cpp
class Outer {
private:
    int outerValue = 10;
    
public:
    class Inner {
    private:
        int innerValue = 20;
        
    public:
        void display(const Outer& o) {
            cout << "Inner: " << innerValue << endl;
            cout << "Outer: " << o.outerValue << endl;
        }
    };
    
    void show() {
        Inner i;
        i.display(*this);
    }
};

int main() {
    Outer::Inner i;  // Access inner class
    return 0;
}
```

---

## 21. Type Casting

### 21.1 static_cast

Compile-time casts.

```cpp
int i = 10;
double d = static_cast<double>(i);

class Base {};
class Derived : public Base {};
Derived* d = new Derived();
Base* b = static_cast<Base*>(d);  // Upcasting
Derived* d2 = static_cast<Derived*>(b);  // Downcasting
```

### 21.2 dynamic_cast

Runtime-safe downcasting (requires RTTI).

```cpp
class Base { public: virtual ~Base() {} };
class Derived : public Base { void special() {} };

Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b);  // Returns valid pointer
Base* b2 = new Base();
Derived* d2 = dynamic_cast<Derived*>(b2);  // Returns nullptr
```

### 21.3 const_cast

Remove/add const.

```cpp
void modify(const string* s) {
    string* mod = const_cast<string*>(s);
    *mod = "modified";
}
```

### 21.4 reinterpret_cast

Unsafe, implementation-specific conversion.

```cpp
int* p = new int(42);
void* vp = reinterpret_cast<void*>(p);
int* p2 = reinterpret_cast<int*>(vp);
```

---

## Quick Reference

| Concept | Keyword/Feature |
|---------|----------------|
| Data hiding | `private` |
| Inheritance | `: public Base` |
| Polymorphism | `virtual`, `override` |
| Abstraction | Pure virtual (`= 0`) |
| Static member | `static` |
| Const method | `const` |
| Friend | `friend` |
| Template | `template<typename T>` |
| Smart pointer | `unique_ptr`, `shared_ptr` |
| Move semantics | `&&`, `std::move` |
| Virtual inheritance | `virtual` |

---

## Common Interview Questions

1. **What is the difference between struct and class?**
   - Default access: struct = public, class = private

2. **What is slicing?**
   - When a derived object is assigned to base object, derived part is "sliced" off

3. **What is vtable?**
   - Virtual function table - compiler-generated table for dynamic dispatch

4. **What is the order of constructor/destructor call in inheritance?**
   - Constructors: Base → Derived
   - Destructors: Derived → Base

5. **Can virtual functions be private?**
   - Yes, but derived classes cannot override them if private in base

6. **What is RTTI?**
   - Runtime Type Information - enables `dynamic_cast` and `typeid`

7. **What is the diamond problem?**
   - Ambiguity in multiple inheritance when same base inherited via two paths

8. **When to use virtual destructors?**
   - Always, when class has virtual functions (for proper cleanup via base pointer)

---

*End of OOPS Guide*
