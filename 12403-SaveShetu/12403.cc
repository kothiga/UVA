#include <iostream>
#include <string>

using namespace std;

int main() {

   int N;
   cin >> N;

   int total = 0;
   while (N--) {

      string s;
      cin >> s;

      if (s == "donate") {
	 int d;
	 cin >> d;
	 total += d;
      } else {
	 cout << total << endl;
      }
   }
}
