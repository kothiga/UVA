#include <iostream>

using namespace std;

typedef unsigned long long ll;

const int MAX_B = 104;
const int MAX_T = 64;
const ll  RESET = 0;

ll table[MAX_B][MAX_T];

void clear() {
   for (int i = 0; i < MAX_B; i++)
      for (int j = 0; j < MAX_T; j++) 
	 table[i][j] = RESET;
}

ll solve(int t, int b) {

   if (table[b][t] != RESET) {
      return table[b][t];
   }

   if (b == 1) {
      return table[b][t] = t;
   }

   if (t == 0) {
      return 0;
   }

   return table[b][t] = solve(t-1, b) + solve(t-1, b-1) + 1;
}

int main() {

   int k; ll n;
   while (cin >> k >> n && (k && n)) {

      clear();

      bool found = false;
      for (int t = 1; t < MAX_T; t++) {
	 if (solve(t, k) >= n) {
	    cout << t << endl;
	    found = true;
	    break;
	 }
      }

      if (!found) {
	 cout << "More than 63 trials needed." << endl;
      }      
   }

   return 0;
}
