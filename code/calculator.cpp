#include<iostream>
using namespace std;

void addition(int a , int b){
    cout<<endl;
    cout << a + b;
}
void subtract(int a , int b){
    if(a>b){
        cout<<endl;
        cout << a - b;
    } else {
        cout<<endl;
        cout << b - a;
    }
}
void multiply(int a , int b){
    cout<<endl;
    cout<< a * b << endl;
}
void divide(int a , int b){
    if(b!=0){
        float ans = (float) a / b;
        cout << endl;
        cout << ans << endl;
    } else {
        cout <<"INVALID OPERANDS!!"<<endl;
    }
}

int main(){
    int choice;
    int a , b;
    cout << "Enter The Expected Operation To Perform"<<endl;
    cout << "1.Sum 2.Subtract 3.Multiply 4.Divide : ";
    cin >> choice;
    cout << "Enter Two Numbers To Perform : ";
    cin >> a;
    cin >> b;
    switch(choice){
        case 1:
        addition(a,b);
        break;
        case 2:
        subtract(a,b);
        break;
        case 3:
        multiply(a,b);
        break;
        case 4:
        divide(a,b);
        break;
        default:
        cout << "INVALID CHOICE!!!" <<endl;
    }
    return 0;
}