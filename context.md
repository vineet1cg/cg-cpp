# C++ Codebase Context & Documentation

## Overview

This repository contains C++ learning materials covering fundamentals, OOPS concepts, STL, and practical programs. Organized into `code/` (source files) and `notes/` (documentation).

---

## Directory Structure

```
SAMIR-SIR-CPP/
├── code/
│   ├── OOPS/          # Object-Oriented Programming examples
│   │   ├── 01.cpp     # Basic class & object
│   │   ├── 02.cpp     # Constructor & Destructor
│   │   ├── 03.cpp     # (incomplete)
│   │   └── structured.cpp  # Advanced OOPS (inheritance, polymorphism)
│   ├── stl/           # Standard Template Library
│   │   ├── 1.cpp      # Vector & algorithms
│   │   └── 2.cpp      # Array STL
│   ├── hello.cpp      # File reading
│   ├── primitive.cpp  # Data types
│   ├── array.cpp      # Arrays
│   ├── palindrome.cpp # Palindrome check
│   ├── evenOdd.cpp    # Even/Odd & Positive/Negative
│   ├── calculator.cpp # Calculator using switch
│   └── storeInput.cpp # File writing
├── notes/
│   ├── 00.md          # C++ fundamentals
│   └── 00llm.md       # Extended notes
└── context.md         # This file
```

---

## 1. Basic Programs

### 1.1 Hello World (`01.cpp`)

**Syntax:**
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
```

**Usage:** Basic program structure, input/output with `cout` and `cin`.

---

### 1.2 Primitive Data Types (`primitive.cpp`)

| Type | Description | Size (typical) |
|------|-------------|----------------|
| `int` | Integer | 4 bytes |
| `float` | Single precision float | 4 bytes |
| `double` | Double precision float | 8 bytes |
| `char` | Single character | 1 byte |
| `bool` | Boolean (true/false) | 1 byte |
| `short` | Short integer | 2 bytes |
| `long` | Long integer | 4/8 bytes |
| `long long` | Very long integer | 8 bytes |

**Syntax:**
```cpp
int number = 10;
float piFloat = 3.14f;
double piDouble = 3.141592653589793;
char initial = 'A';
bool isStudent = true;
```

---

### 1.3 Arrays (`array.cpp`)

**Syntax:**
```cpp
int numbers[5] = {1, 2, 3, 4, 5};

// Get size
int size = sizeof(numbers) / sizeof(numbers[0]);

// Access elements
for (int i = 0; i < size; i++) {
    cout << numbers[i] << endl;
}
```

**Notes:**
- Fixed size in C++
- Stored contiguously in memory
- No bounds checking

---

### 1.4 Even/Odd Check (`evenOdd.cpp`)

**Syntax:**
```cpp
int n;
cin >> n;

// Using bitwise AND (faster)
if (n & 1)
    cout << "Odd";
else
    cout << "Even";

// Check positive/negative
if (n > 0)
    cout << "Positive";
else
    cout << "Negative";
```

---

### 1.5 Palindrome (`palindrome.cpp`)

**Syntax:**
```cpp
int n, temp, rev = 0;
temp = n;
while (temp != 0) {
    rev = rev * 10 + (temp % 10);
    temp = temp / 10;
}
if (rev == n)
    cout << "Palindrome";
```

---

### 1.6 Calculator (`calculator.cpp`)

**Syntax:**
```cpp
int choice, a, b;
cin >> choice >> a >> b;

switch(choice) {
    case 1: addition(a, b); break;
    case 2: subtract(a, b); break;
    case 3: multiply(a, b); break;
    case 4: divide(a, b); break;
    default: cout << "Invalid"; break;
}
```

---

## 2. File I/O

### 2.1 Reading Files (`hello.cpp`)

**Syntax:**
```cpp
#include <fstream>
#include <string>

ifstream file("sample.txt");
string line;
while (getline(file, line)) {
    cout << line << endl;
}
file.close();
```

---

### 2.2 Writing Files (`storeInput.cpp`)

**Syntax:**
```cpp
#include <fstream>

fstream file;
file.open("db.txt", ios::out | ios::app);  // append mode
if (file.is_open()) {
    file << "data" << endl;
    file.close();
}
```

**File Modes:**
- `ios::in` - Read
- `ios::out` - Write
- `ios::app` - Append
- `ios::trunc` - Truncate/overwrite

---

## 3. Object-Oriented Programming (OOPS)

### 3.1 Class & Object (`01.cpp`)

**Syntax:**
```cpp
class Car {
public:
    string brand;
    int mileage;
    string engine;
    
    void print() {
        cout << brand << endl;
    }
};

int main() {
    Car c1;
    c1.brand = "Toyota";
    c1.print();
    
    Car c2 = {brand: "Lamborghini", mileage: 15, engine: "V10"};
}
```

---

### 3.2 Constructor & Destructor (`02.cpp`)

**Syntax:**
```cpp
class Student {
public:
    string name;
    int age;
    
    // Constructor - same name as class, no return type
    Student(string n, int a) {
        this->name = n;  // 'this' refers to current object
        age = a;
    }
    
    // Destructor - ~classname
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }
};
```

**Key Points:**
- Constructor called when object created
- Destructor called when object goes out of scope
- No garbage collector in C++ - memory managed manually
- Use `new`/`delete` for heap allocation

---

### 3.3 Inheritance (`Inheritence.cpp`)

**Syntax:**
```cpp
class Animal {
public:
    void eat() { cout << "Eating..." << endl; }
};

class Dog : public Animal {  // Dog inherits from Animal
public:
    void bark() { cout << "Woof!" << endl; }
};

int main() {
    Dog myDog;
    myDog.eat();  // Inherited method
    myDog.bark(); // Own method
}
```

**Inheritance Types:**
- `public` - Public and protected members stay accessible
- `protected` - Public becomes protected
- `private` - All members become private

---

### 3.4 Advanced OOPS (`structured.cpp`)

#### Encapsulation
```cpp
class Animal {
private:      // Only accessible within class
    string name_;
    int age_;
    
protected:    // Accessible in derived classes
    string species_;
    
public:       // Accessible everywhere
    string getName() const { return name_; }
};
```

#### Polymorphism (Virtual Functions)
```cpp
class Animal {
public:
    virtual void speak() const {
        cout << "Generic sound" << endl;
    }
    virtual ~Animal() {}  // Virtual destructor important!
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof!" << endl;
    }
};

int main() {
    Animal* ptr = new Dog();
    ptr->speak();  // Calls Dog's speak() - runtime polymorphism
    delete ptr;
}
```

#### Constructor Chaining
```cpp
class Dog : public Animal {
    string breed_;
public:
    Dog(string name, int age, string breed)
        : Animal(name, age, "Dog"),  // Call base constructor
          breed_(breed) {
        cout << "Dog constructor" << endl;
    }
};
```

#### Smart Pointers (Memory Management)
```cpp
#include <memory>
#include <vector>

vector<unique_ptr<Animal>> animals;
animals.push_back(make_unique<Dog>("Buddy", 3, "Golden"));
// Automatically deleted when vector goes out of scope
```

**Execution Order:**
1. Base constructor
2. Derived constructor
3. Derived destructor
4. Base destructor

---

## 4. Standard Template Library (STL)

### 4.1 Vector (`stl/1.cpp`)

**Syntax:**
```cpp
#include <vector>
#include <algorithm>

vector<int> vec(n);  // Size n
vector<int> vec = {1, 2, 3};

// Add elements
vec.push_back(4);

// Sort & Reverse
sort(vec.begin(), vec.end());
reverse(vec.begin(), vec.end());

// Write to file
ofstream out("output.txt");
for (const auto& val : vec) {
    out << val << ' ';
}
```

---

### 4.2 Array STL (`stl/2.cpp`)

**Syntax:**
```cpp
#include <array>

array<int, 5> arr = {1, 2, 3, 4, 5};
cout << arr[0];
cout << arr.at(0);  // Bounds checked

// Size
arr.size();
arr.empty();
```

---

## 5. Compilation & Running

### Compile
```bash
g++ filename.cpp -o output
# or
g++ filename.cpp -o output.exe
```

### Run
```bash
./output
# or
output.exe
```

### With C++11/14/17
```bash
g++ -std=c++17 filename.cpp -o output
```

---

## 6. Common Notes

### Memory Management
- **Stack:** Automatic cleanup when scope ends
- **Heap:** Manual `new`/`delete` required
- **No garbage collector** unlike Java/Python

### Best Practices
1. Use `const` for read-only methods
2. Use `virtual` destructors for polymorphic classes
3. Prefer `std::vector` over raw arrays
4. Use smart pointers (`unique_ptr`, `shared_ptr`)
5. Initialize variables before use
6. Check file operations with `is_open()`

### Common Errors
- Forgetting `&` in pass-by-reference
- Missing return statement in non-void function
- Using `=` instead of `==` in comparisons
- Not initializing arrays
- Memory leaks from missing `delete`

---

## 7. Quick Reference

| Concept | Syntax |
|---------|--------|
| Class | `class Name { };` |
| Object | `ClassName obj;` |
| Constructor | `Name() { }` |
| Destructor | `~Name() { }` |
| Inheritance | `class Derived : public Base { }` |
| Virtual function | `virtual void func() { }` |
| Override | `void func() override { }` |
| Pointer | `Type* ptr = &obj;` |
| Reference | `Type& ref = obj;` |
| Template | `template<typename T> void func(T val) { }` |

---

*Generated from codebase analysis*
