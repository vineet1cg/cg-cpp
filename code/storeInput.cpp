#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    string usr_input;
    cout << "Enter Input: ";
    getline(cin, usr_input);

    fstream dbfile;
    dbfile.open("db.txt", ios::out | ios::app);

    if (dbfile.is_open()) {
        dbfile << usr_input << endl;
        dbfile.close();
    } else {
        cout << "Error opening file!" << endl;
    }

    return 0;
}
