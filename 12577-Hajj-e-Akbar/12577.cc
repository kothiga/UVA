#include <iostream>
#include <string>

using namespace std;

int main() {

   string s;

   string a = "Hajj-e-Akbar\n";
   string b = "Hajj-e-Asghar\n";

   int c = 1;
   while (cin >> s && s != "*") {
      cout << "Case " << c++ << ": ";

      if (s == "Hajj") {
	 cout << a;
      } else {
	 cout << b;
      }	 
   }
}
