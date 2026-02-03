# Primitive Data Types in C++

Primitive data types are the basic building blocks used to store and manipulate data. They include:

1. **int**: Used to store integer values.
   ```cpp
   int number = 10;
   ```

2. **float**: Used to store floating-point numbers with single precision (7 decimal digits).
   ```cpp
   float piFloat = 3.14f;
   ```

3. **double**: Used to store floating-point numbers with double precision (15 decimal digits).
   ```cpp
   double piDouble = 3.141592653589793;
   ```

4. **char**: Used to store a single character enclosed in quotes.
   ```cpp
   char initial = 'A';
   ```

5. **bool**: Used to store boolean values (`true` or `false`).
   ```cpp
   bool isStudent = true;
   ```

6. **short**: Used to store short integer values.
   ```cpp
   short smallNumber = 100;
   ```

7. **long**: Used to store long integer values.
   ```cpp
   long largeNumber = 123456789L;
   ```

8. **long long**: Used to store very large integer values.
   ```cpp
   long long veryLargeNumber = 123456789012345LL;
   ```

Each primitive data type has specific storage sizes, which can be determined using the `sizeof` operator. For example:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    // ... and so on for other types
    return 0;
}
```

Using the correct primitive data type is crucial for efficient memory usage and performance in C++.

# Array Data Types in C++

An array is a collection of elements of the same data type stored in contiguous memory locations. Below is an example demonstrating how to declare, initialize, access, and print elements in an array using C++.

## Declaration and Initialization

```cpp
int numbers[5] = {1, 2, 3, 4, 5};
```

- This line declares an integer array named `numbers` with 5 elements and initializes them to `{1, 2, 3, 4, 5}`.

## Printing the Size of the Array

```cpp
cout << "Number of elements in the array: " << sizeof(numbers) / sizeof(numbers[0]) << endl;
```

- `sizeof(numbers)` gives the total size of the array in bytes.
- `sizeof(numbers[0])` gives the size of one element in the array (in this case, 4 bytes for an integer).
- Dividing these two values gives the number of elements in the array.

## Accessing and Printing Each Element

```cpp
for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
    cout << "Element at index " << i << ": " << numbers[i] << endl;
}
```

- A `for` loop iterates through each element of the array.
- Inside the loop, the value of each element is accessed using `numbers[i]` and printed.

This example demonstrates how to declare, initialize, access, and print elements in an array in C++. The comments provide clear explanations for each part of the code.