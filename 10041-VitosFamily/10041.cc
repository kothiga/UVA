#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main() {

   const int MAX = 505;
   int input[MAX] = {0};
   
   int N; cin >> N;

   while (N--) {

      int R; cin >> R;

      if (R == 0) {
	 cout << 0 << endl;
	 continue;
      }

      for (int i = 0; i < R; i++) {
	 cin >> input[i];
      }

      sort(input, input+R);

      int median = R / 2;
      int dist = 0;
      for (int i = 0; i < R; i++) {
	 dist += abs(input[i] - input[median]);
      }

      cout << dist << endl;
   }

   return 0;
}
