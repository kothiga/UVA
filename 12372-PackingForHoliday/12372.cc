#include <iostream>

using namespace std;

int main() {

   int N;
   cin >> N;

   for (int i = 0; i < N; i++) {
      bool yes = true;

      int a, b, c;
      cin >> a >> b >> c;

      if (a > 20 || b > 20 || c > 20) {
	 yes = false;
      }

      cout << "Case " << i+1 << ": ";
      if (yes) {
	 cout << "good\n";
      } else {
	 cout << "bad\n";
      }
   }

}
