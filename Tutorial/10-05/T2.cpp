#include <iostream>
#include <string>

using namespace std;

int main() {
  string str = "Do not interrupt me";
  char ch = 'm';
	
  // use cout with write()
  cout.write(str,6);

  cout << endl;

  // use cout with put()
  cout.put(ch);
	
  return 0;
}