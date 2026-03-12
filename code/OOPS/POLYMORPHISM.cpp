#include <iostream>
#include <string>
using namespace std;

// fucntion overlaod means when you are defining the same fucntion number of times in a same class but with either different number of argumnets or different data types...

class Poly
{
private:
    int a1, b1;

public:
    Poly(int a, int b)
    {
        a1 = a;
        b1 = b;
        cout << "A1 value is: " << a1 << " and B1 value is: " << b1 << endl;
    }

    int operator+(Poly &p2)
    {
        int c = this->a1 - p2.b1;
        return c;
    }

    void operator()()
    {
        cout << "Good Morning" << endl;
    }

    void operator++()
    {
        a1 += 5;
        b1 -= 10;

        cout << this->a1 << " and " << this->b1 << endl;
    }

    void operator++(int)
    {
        --a1;
        --b1;
        cout << this->a1 << " and" << this->b1 << endl;
    }

    void add(int a, int b)
    {
        cout << "Addition of two number is: " << a + b << endl;
    }

    void add(int a, int b, int c)
    {
        cout << "Addition of two number is: " << a + b << endl;
    }

    int add(double a, double b)
    {
        cout << "Addition of two number is: " << a + b << endl;
        return 0;
    }
    char add(string a, int b)
    {
        cout << a + char(b) << endl;
        return 'A';
    }
};

int main()
{

    Poly p1(23, 56);
    Poly p2(56, -45);

    cout << p1 + p2 << endl;

    p1();

    p1++;

    ++p1;

    // p1.add(10, 20);
    // int b = p1.add(12.23, 78.3);
    // char c = p1.add("Samir" , 68);
    return 0;
}