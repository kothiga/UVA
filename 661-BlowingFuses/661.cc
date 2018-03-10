#include <iostream>

using namespace std;

int main() {
   int n, m, c;
   int CASE = 1;
   while (cin >> n >> m >> c && (n || m || c)) {

      int devices[21];
      bool d[21];

      for (int i = 0; i < n; i++) {
	 int x;
	 cin >> x;
	 devices[i] = x;
	 d[i] = false;
      }

      bool blew = false;
      int max = 0;
      int total = 0;

      for (int i = 0; i < m; i++) {
	 int x;
	 cin >> x;
	 x -= 1;
	 
	 if (d[x]) { // x was turned off
	    
	    d[x] = !d[x];
	    total -= devices[x];
	    
	 } else { // x was turned on
	    
	    d[x] = !d[x];
	    total += devices[x];

	    if (total > c) {
	       blew = true;
	    }

	    if (total > max) {
	       max = total;
	    }
	    
	 }
      }

      if (total > max) {
	 max = total;
      }

      cout << "Sequence " << CASE++ << endl;
      if (!blew) {
	 cout << "Fuse was not blown.\nMaximal power consumption was "
	      << max << " amperes.\n\n";
      } else {
	 cout << "Fuse was blown.\n\n";
      }
   
   }
}
