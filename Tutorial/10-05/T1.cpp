#include <iostream>
using namespace std;

int main() {
  int num1, num2, num3;

  cout << "Enter a number: ";

  // for single input
  cin >> num1;

  cout << "Enter 2 numbers: ";

  // for multiple inputs
  cin >> num2 >> num3;

  cout << "Sum = " << (num1 + num2 + num3) << endl;

  return 0;
}