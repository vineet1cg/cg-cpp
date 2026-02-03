// array.cpp

#include <iostream>
using namespace std;

int main() {
    // Declare and initialize an integer array with 5 elements
    int numbers[5] = {1, 2, 3, 4, 5};
    
    // Print the size of the array (number of elements)
    cout << "Number of elements in the array: " << sizeof(numbers) / sizeof(numbers[0]) << endl;

    // Access and print each element of the array
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        cout << "Element at index " << i << ": " << numbers[i] << endl;
    }

    return 0;
}