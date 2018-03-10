#include <iostream>

using namespace std;

int main () {

   int n;
   cin >> n;
   while (n--) {

      int i, j;
      cin >> i >> j;

      if (i == j) {
	 cout << "=\n";
      } else if (i > j) {
	 cout << ">\n";
      } else {
	 cout << "<\n";
      }
   }
}
