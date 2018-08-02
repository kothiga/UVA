#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 105;
int power[MAX];

bool solve(int m, int n) {

   fill(power, power+MAX, 1);

   int pos = 0;
   for (int i = 0; i < n-1; i++) {

      power[pos] = 0;
      
      int mcount = 0;
      while (mcount < m) {
	 pos = (pos + 1) % n;
	 if (power[pos] != 0) {
	    mcount++;
	 }
      }
      if (power[12] == 0) {
	 return false;
      }
   }

   return true;
}


int main() {
   
   int N;
   while (cin >> N && N) {

      for (int i = 1; i < MAX; i++) {
	 if (solve(i, N)) {	    
	    cout << i << endl;
	    break;
	 }
      }
   }

   return 0;
}
