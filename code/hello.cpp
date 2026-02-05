#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string onelineStatement;
    ifstream file1("sample.txt");

    if (file1.is_open()) {
        while (getline(file1, onelineStatement)) {
            cout << onelineStatement << endl;
        }
        file1.close();
    } else {
        cout << "Failed to open file." << endl;
    }

    return 0;
}
