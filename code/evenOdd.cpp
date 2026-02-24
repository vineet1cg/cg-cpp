#include<iostream>
using namespace std;

int main(){
  int n;
  cout << "Enter Number : ";
  cin >> n;
  cout << endl;
  if(n&1){
    cout << "Odd" << endl;
  } else {
    cout << "Even" << endl;
  }
  if(n>0){
    cout<< "Positive" << endl;
  } else {
    cout << "Negative" << endl;
  }
  
  return 0;
}