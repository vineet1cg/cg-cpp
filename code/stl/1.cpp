#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << "Enter size of vector: ";
    size_t n;
    cout << "Enter size of vector: ";
    cin >> n;
    vector<int> vec(n); // Initialize a vector with the specified size


    // Explanation: This code prompts the user to enter the size of the vector, reads it, and then initializes a vector of that size.
    // The vector is used to store integers, which can be manipulated using standard algorithms and functions.
    // The placeholder comment explains what this section does.


    vector<int> vec(n);
    cout << "Enter " << n << " elements:\n";
    for (size_t i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    ofstream out("output.txt");
    for (const auto& val : vec) {
        out << val << ' ';
    }
    out << '\n';
    return 0;
}
