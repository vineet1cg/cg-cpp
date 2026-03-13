#include <iostream>
#include <string>
#include <memory>
using namespace std;


// =============================================================================
// POLYMORPHISM IN C++
// =============================================================================
//
// Polymorphism is one of the four pillars of Object-Oriented Programming (OOP).
// The word "Polymorphism" comes from Greek words:
//   - "Poly" means "Many"
//   - "Morphos" means "Forms"
//
// So, polymorphism means "many forms". It allows a single interface to be used
// for different underlying forms (data types).
//
// In C++, there are two main types of polymorphism:
//
// 1. COMPILE-TIME (STATIC) POLYMORPHISM
//    - Resolved at compile time
//    - Includes: Function Overloading, Operator Overloading
//
// 2. RUNTIME (DYNAMIC) POLYMORPHISM
//    - Resolved at runtime
//    - Includes: Function Overriding, Virtual Functions
//
// =============================================================================


// =============================================================================
// PART 1: COMPILE-TIME POLYMORPHISM
// =============================================================================


// -----------------------------------------------------------------------------
// 1A. FUNCTION OVERLOADING
// -----------------------------------------------------------------------------
// Function overloading is when we have multiple functions with the SAME NAME
// but different parameters (either different number of parameters or different
// data types).
//
// The compiler decides which function to call based on the arguments passed.

class Calculator {
public:
    // Adding 2 integers
    int add(int a, int b) {
        cout << "add(int, int) called" << endl;
        return a + b;
    }

    // Adding 3 integers - same name but different number of parameters
    int add(int a, int b, int c) {
        cout << "add(int, int, int) called" << endl;
        return a + b + c;
    }

    // Adding 2 doubles - same name but different parameter types
    double add(double a, double b) {
        cout << "add(double, double) called" << endl;
        return a + b;
    }

    // Adding string and integer
    string add(string s, int n) {
        cout << "add(string, int) called" << endl;
        return s + to_string(n);
    }
};


// -----------------------------------------------------------------------------
// 1B. OPERATOR OVERLOADING
// -----------------------------------------------------------------------------
// Operator overloading allows operators to be used with user-defined types.
// We can redefine the meaning of operators for custom classes.

class Box {
private:
    int length;
    int width;

public:
    Box(int l = 0, int w = 0) : length(l), width(w) {}

    // Overloading the + operator to add two Box objects
    Box operator+(const Box& other) {
        Box result;
        result.length = this->length + other.length;
        result.width = this->width + other.width;
        return result;
    }

    // Overloading the - operator
    Box operator-(const Box& other) {
        Box result;
        result.length = this->length - other.length;
        result.width = this->width - other.width;
        return result;
    }

    // Overloading the * operator (scalar multiplication)
    Box operator*(int scalar) {
        Box result;
        result.length = this->length * scalar;
        result.width = this->width * scalar;
        return result;
    }

    // Overloading == operator
    bool operator==(const Box& other) {
        return (this->length == other.length && this->width == other.width);
    }

    // Function to display box dimensions
    void display() const {
        cout << "Box: Length = " << length << ", Width = " << width << endl;
    }
};


// =============================================================================
// PART 2: RUNTIME POLYMORPHISM
// =============================================================================


// -----------------------------------------------------------------------------
// 2A. FUNCTION OVERRIDING (USING INHERITANCE)
// -----------------------------------------------------------------------------
// Function overriding occurs when a derived class provides a specific
// implementation of a function already defined in its base class.
// The function in the derived class must have the SAME signature as in base.

// Base class
class Animal {
public:
    // Virtual function - can be overridden by derived classes
    // The 'virtual' keyword enables runtime polymorphism
    virtual void speak() const {
        cout << "Animal makes a sound" << endl;
    }

    // Virtual destructor - IMPORTANT when using polymorphism
    // Ensures proper cleanup of derived class objects through base class pointers
    virtual ~Animal() {
        cout << "Animal destructor called" << endl;
    }

    // Non-virtual function - will not be overridden
    void sleep() const {
        cout << "Animal is sleeping" << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    // Override the speak() function
    // 'override' keyword (C++11) ensures we're actually overriding a virtual function
    void speak() const override {
        cout << "Dog says: Woof! Woof!" << endl;
    }

    // Dog-specific function
    void fetch() const {
        cout << "Dog fetches the ball" << endl;
    }

    ~Dog() {
        cout << "Dog destructor called" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void speak() const override {
        cout << "Cat says: Meow! Meow!" << endl;
    }

    void scratch() const {
        cout << "Cat scratches" << endl;
    }

    ~Cat() {
        cout << "Cat destructor called" << endl;
    }
};

// Derived class 3
class Cow : public Animal {
public:
    void speak() const override {
        cout << "Cow says: Moo! Moo!" << endl;
    }

    ~Cow() {
        cout << "Cow destructor called" << endl;
    }
};


// -----------------------------------------------------------------------------
// 2B. PURE VIRTUAL FUNCTIONS & ABSTRACT CLASSES
// -----------------------------------------------------------------------------
// A pure virtual function is a virtual function that has no implementation
// in the base class. It's declared by assigning 0 to it.
//
// A class containing at least one pure virtual function becomes an
// ABSTRACT CLASS. We cannot create objects of an abstract class,
// but we can create pointers and references to it.

class Shape {
protected:
    string color;

public:
    Shape(string c = "white") : color(c) {}

    // Pure virtual function - must be overridden by derived classes
    virtual double area() const = 0;

    // Another pure virtual function
    virtual void draw() const = 0;

    // Virtual function with default implementation
    virtual void setColor(string c) {
        color = c;
    }

    string getColor() const {
        return color;
    }

    // Virtual destructor
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h, string c = "blue") : Shape(c), width(w), height(h) {}

    // Implementing pure virtual function
    double area() const override {
        return width * height;
    }

    void draw() const override {
        cout << "Drawing a Rectangle with width " << width 
             << " and height " << height << endl;
    }

    ~Rectangle() {
        cout << "Rectangle destructor" << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, string c = "red") : Shape(c), radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        cout << "Drawing a Circle with radius " << radius << endl;
    }

    ~Circle() {
        cout << "Circle destructor" << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h, string c = "green") : Shape(c), base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }

    void draw() const override {
        cout << "Drawing a Triangle with base " << base 
             << " and height " << height << endl;
    }

    ~Triangle() {
        cout << "Triangle destructor" << endl;
    }
};


// =============================================================================
// PART 3: VIRTUAL FUNCTION TABLE (VTABLE)
// =============================================================================
//
// When a class contains virtual functions, the compiler creates a VTABLE
// (also called virtual function table or virtual table) for that class.
//
// Each object of that class contains a hidden VPTR (virtual pointer)
// that points to the VTABLE.
//
// How it works:
// 1. When a virtual function is called through a base class pointer,
//    the compiler uses the VPTR to look up the correct function address
//    at RUNTIME (not compile time).
// 2. This is called DYNAMIC DISPATCH or LATE BINDING.
//
// Example:
//   Animal* ptr = new Dog();
//   ptr->speak();  // Calls Dog::speak() at runtime, not Animal::speak()


// =============================================================================
// PART 4: SMART POINTERS WITH POLYMORPHISM
// =============================================================================
//
// Smart pointers automatically manage memory and help prevent memory leaks.
// They also work well with polymorphism.


// =============================================================================
// MAIN FUNCTION - DEMONSTRATING ALL CONCEPTS
// =============================================================================

int main() {
    cout << "=================================================================" << endl;
    cout << "                    POLYMORPHISM DEMONSTRATION                   " << endl;
    cout << "=================================================================" << endl << endl;


    // =========================================================================
    // DEMO 1: FUNCTION OVERLOADING
    // =========================================================================
    cout << "=== DEMO 1: FUNCTION OVERLOADING ===" << endl;
    Calculator calc;

    int sum1 = calc.add(10, 20);           // Calls add(int, int)
    int sum2 = calc.add(10, 20, 30);       // Calls add(int, int, int)
    double sum3 = calc.add(5.5, 3.3);      // Calls add(double, double)
    string sum4 = calc.add("Number: ", 42); // Calls add(string, int)

    cout << "Results: " << sum1 << ", " << sum2 << ", " << sum3 << ", " << sum4 << endl;
    cout << endl;


    // =========================================================================
    // DEMO 2: OPERATOR OVERLOADING
    // =========================================================================
    cout << "=== DEMO 2: OPERATOR OVERLOADING ===" << endl;
    Box b1(5, 3);
    Box b2(2, 4);

    cout << "Box 1: "; b1.display();
    cout << "Box 2: "; b2.display();

    Box b3 = b1 + b2;   // Using overloaded + operator
    cout << "Box 1 + Box 2: "; b3.display();

    Box b4 = b1 * 3;    // Scalar multiplication
    cout << "Box 1 * 3: "; b4.display();

    if (b1 == b2) {
        cout << "Box 1 and Box 2 are equal" << endl;
    } else {
        cout << "Box 1 and Box 2 are NOT equal" << endl;
    }
    cout << endl;


    // =========================================================================
    // DEMO 3: RUNTIME POLYMORPHISM WITH VIRTUAL FUNCTIONS
    // =========================================================================
    cout << "=== DEMO 3: RUNTIME POLYMORPHISM ===" << endl;

    // Creating objects of different classes
    Animal* animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cow();

    // Calling speak() through base class pointer
    // The correct function is called at RUNTIME
    for (int i = 0; i < 3; i++) {
        animals[i]->speak();  // Polymorphic call!
    }

    // Non-virtual function call - binds at compile time
    cout << "\nCalling non-virtual function:" << endl;
    animals[0]->sleep();  // Calls Animal::sleep()

    // Clean up - virtual destructors ensure proper cleanup
    cout << "\nCleaning up:" << endl;
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
    cout << endl;


    // =========================================================================
    // DEMO 4: ABSTRACT CLASSES & PURE VIRTUAL FUNCTIONS
    // =========================================================================
    cout << "=== DEMO 4: ABSTRACT CLASSES ===" << endl;

    // Cannot create object of Shape (abstract class)
    // Shape s;  // ERROR!

    // But can create pointers to abstract class
    Shape* shapes[3];
    shapes[0] = new Rectangle(5, 3);
    shapes[1] = new Circle(4);
    shapes[2] = new Triangle(6, 4);

    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Color: " << shapes[i]->getColor() << endl;
        cout << endl;
    }

    // Using reference for polymorphism
    Rectangle rect(10, 5, "yellow");
    Shape& shapeRef = rect;  // Reference to derived class object
    cout << "Area through Shape reference: " << shapeRef.area() << endl;

    // Clean up
    cout << "\nCleaning up shapes:" << endl;
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }
    cout << endl;


    // =========================================================================
    // DEMO 5: SMART POINTERS WITH POLYMORPHISM
    // =========================================================================
    cout << "=== DEMO 5: SMART POINTERS ===" << endl;

    // Using unique_ptr (C++11)
    unique_ptr<Animal> pet1 = make_unique<Dog>();
    unique_ptr<Animal> pet2 = make_unique<Cat>();

    pet1->speak();  // Polymorphic call with smart pointer
    pet2->speak();

    // No manual delete needed - smart pointer handles cleanup automatically
    cout << "Smart pointers automatically cleaned up!" << endl;


    // =========================================================================
    // SUMMARY
    // =========================================================================
    cout << "\n=================================================================" << endl;
    cout << "                         SUMMARY                                 " << endl;
    cout << "=================================================================" << endl;
    cout << "1. FUNCTION OVERLOADING: Same name, different parameters" << endl;
    cout << "2. OPERATOR OVERLOADING: Redefine operators for custom types" << endl;
    cout << "3. FUNCTION OVERRIDING: Derived class redefines base class function" << endl;
    cout << "4. VIRTUAL FUNCTIONS: Enable runtime polymorphism" << endl;
    cout << "5. PURE VIRTUAL FUNCTIONS: Abstract classes (interfaces)" << endl;
    cout << "6. VTABLE: Compiler mechanism for runtime polymorphism" << endl;
    cout << "=================================================================" << endl;

    return 0;
}
