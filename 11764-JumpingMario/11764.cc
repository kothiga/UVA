#include <iostream>

using namespace std;

int main() {

   int N;
   cin >> N;

   for (int i = 0; i < N; i++) {

      int h = 0;
      int l = 0;
      
      int n;
      cin >> n;

      int last = -1;
      for (int j = 0; j < n; j++) {
	 
	 int cur;
	 cin >> cur;

	 if (last == -1) {
	    last = cur;
	    continue;
	 }

	 if (cur > last) {
	    l++;
	 } else if (cur < last) {
	    h++;
	 }
	 
	 last = cur;
      }

      cout << "Case " << i+1 << ": " << l << " " << h << endl;
   }
}
