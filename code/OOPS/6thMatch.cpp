#include <iostream>
#include <string>

using namespace std;

class CodingGita
{

public:
    // Data members...
    string sName;
    static string organization;
    int roll;
    static int tStudent;

    // Constructor...
    CodingGita(string name, int rn)
    {
        sName = name;
        roll = rn;
        ++tStudent;
    }

    //  Function members....

    void display()
    {
        cout << "Student name is:->" << this->sName << endl;
        cout << "Roll no is:-> " << this->roll << endl;
        cout << "Total number of student is:-> " << this->tStudent << endl;
        cout << "organization name is:->" << this->organization << endl;
    }
};

string CodingGita::organization = "CodingGita";
int CodingGita::tStudent = 0;

int main()
{

    CodingGita s1("Samir", 567);
    s1.display();
    CodingGita s2("Amit", 877);
    s2.display();
    CodingGita s3("Aanya", 896);
    s3.display();

    return 0;
}