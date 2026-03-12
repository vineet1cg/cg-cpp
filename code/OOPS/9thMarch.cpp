#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    //   Data members....
    int balance = 0;

protected:
    // Data member...
    string name;

public:
    // Constructor...
    BankAccount(int bal, string name)
    {
        if (bal > 0)
        {
            balance += bal;
            this->name = name;
            cout << "The particular amount got added in your existed balance." << endl;
        }
        else
        {
            cout << "The amount must be greater than zero" << endl;
        }
    }

    friend void display(BankAccount &person);
};

void display(BankAccount &person)
{
    cout << "The total balance of a particular person is:-> " << person.balance << endl;
    cout << "The account holder name of that account is: ->" << person.name << endl;
}

int main()
{

    BankAccount p1(3446, "Samir singh"), p2(785, "Prince"), p3(-3534, "Priyank");

    display(p2);

    return 0;
}