#define recursive_h
#include<iostream>
using namespace std;

template <class T>
void takeInput(T &refrence){
 cin >> refrence;
 while (!cin){
        cout << "\n\tInvalid Input, Try Again: " << endl;
                cout << "\n\t\t Your Input: ";

        cin.clear();
        fflush(stdin);
        cin >> refrence;
 }
}


long long int factorial(long long int n) {
 if(n==1) {
  return 1;
 } else {
  return n*factorial(n-1);
 }
}
int fibonacci(int n) {
 if (n <= 1) {
  return n;
 }
 return fibonacci(n - 1) + fibonacci(n - 2);
}

void Character(char symbol) {
 char value;
 cout<<"Enter Character: ";
  takeInput(value);
 if(symbol!=value) {
  Character(symbol);
  cout << value<<" ";
 }
	
}

void print1(int n) {
 if (!(n < 1)) {

  if (n % 2 == 0) {
   n -= 1;
   print1(n);
  } else {
   print1(n - 2);
   cout << n << " ";
  }
 }


}
void print2(int n) {
 if (!(n < 1)) {

  if (n % 2 == 0) {
   n -= 1;
   print2(n);
  } else {
   cout << n << " ";
   print2(n - 2);
  }
 }


}
double pow(double b, int exp)
{
    if (exp == 0)
    {
        return 1.0;
    }
    return b * pow(b, exp - 1);
}