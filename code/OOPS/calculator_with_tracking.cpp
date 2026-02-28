#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Calculator {
protected:
    static int addCount;
    static int subCount;
    static int mulCount;
    static int divCount;
    
public:
    Calculator() {
        loadCounts();
    }
    
    virtual double calculate(double a, double b) = 0;
    
    static void loadCounts() {
        ifstream file("db.txt");
        if (file.is_open()) {
            file >> addCount >> subCount >> mulCount >> divCount;
            file.close();
        } else {
            addCount = subCount = mulCount = divCount = 0;
        }
    }
    
    static void saveCounts() {
        ofstream file("db.txt");
        if (file.is_open()) {
            file << addCount << " " << subCount << " " << mulCount << " " << divCount;
            file.close();
        }
    }
    
    static void displayStats() {
        cout << "\nOperation Statistics:" << endl;
        cout << "Addition called: " << addCount << " times" << endl;
        cout << "Subtraction called: " << subCount << " times" << endl;
        cout << "Multiplication called: " << mulCount << " times" << endl;
        cout << "Division called: " << divCount << " times" << endl;
    }
};

int Calculator::addCount = 0;
int Calculator::subCount = 0;
int Calculator::mulCount = 0;
int Calculator::divCount = 0;

class Addition : public Calculator {
public:
    double calculate(double a, double b) override {
        addCount++;
        saveCounts();
        return a + b;
    }
};

class Subtraction : public Calculator {
public:
    double calculate(double a, double b) override {
        subCount++;
        saveCounts();
        return a - b;
    }
};

class Multiplication : public Calculator {
public:
    double calculate(double a, double b) override {
        mulCount++;
        saveCounts();
        return a * b;
    }
};

class Division : public Calculator {
public:
    double calculate(double a, double b) override {
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        divCount++;
        saveCounts();
        return a / b;
    }
};

int main() {
    Addition add;
    Subtraction sub;
    Multiplication mul;
    Division div;
    
    double num1, num2;
    int choice;
    
    while (true) {
        cout << "\n=== Calculator Menu ===" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Show Statistics" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 6) break;
        
        if (choice >= 1 && choice <= 4) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            
            Calculator* calc = nullptr;
            double result = 0;
            
            switch (choice) {
                case 1: calc = &add; break;
                case 2: calc = &sub; break;
                case 3: calc = &mul; break;
                case 4: calc = &div; break;
            }
            
            result = calc->calculate(num1, num2);
            cout << "Result: " << result << endl;
        } else if (choice == 5) {
            Calculator::displayStats();
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    
    cout << "\nThank you for using the calculator!" << endl;
    return 0;
}