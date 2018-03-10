#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {
   
   string m[11] = {"zero","one","two","three","four","five",
		   "six","seven","eight","nine","ten"};
   int N;
   cin >> N;

   while (N--) {

      string s;
      cin >> s;

      int best = 0;
      int bestP = 0;
      
      for (int i = 0; i < 11; i++) {

	 string cur = m[i];
	 unsigned int x = min( cur.length(), s.length() );

	 int curP = 0;
	 for (unsigned int j = 0; j < x; j++) {
	    if (cur[j] == s[j]) {
	       curP++;
	    }
	 }

	 if (curP > bestP) {
	    bestP = curP;
	    best = i;
	 }
      }
      cout << best << endl;
   }

}
