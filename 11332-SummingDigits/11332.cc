#include <iostream>

using namespace std;


int look[10] = {1000000000,
		100000000,
		10000000,
		1000000,
		100000,
		10000,
		1000,
		100,
		10,
		1};


int f(int n) {

   if (n < 10) return n;
   
   int t = 0;

   for (int i = 0; i < 10; i++) {
      t += (n/look[i]) % 10;
   }
   
   return f(t);
}

int main() {

   int n;
   while (cin >> n && n) {
      cout << f(n) << endl;      
   }
}
