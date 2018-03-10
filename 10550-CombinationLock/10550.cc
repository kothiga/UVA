#include <iostream>

using namespace std;

int main() {
   
   int a, b, c, d;

   while (cin >> a >> b >> c >> d &&
	  (a || b || c || d)) {

      int total = 0;
      total += 80;   // turn the dial clockwise 2 full
      total += (40 - (b - a)) % 40; // stop at the first number of the comb
      total += 40;   // turn the dial counterclockwise
      total += (40 + (c - b)) % 40; // coninue turning to num 2
      total += (40 - (d - c)) % 40;

      cout << ((double)total * (360.0/40.0)) << endl;
      
   }
}
