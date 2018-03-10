#include <iostream>

using namespace std;

int main() {

   int N, B, H, W;
   while (cin >> N >> B >> H >> W) {

      int cost = B+1;

      for (int i = 0; i < H; i++) {

	 int p;
	 cin >> p;
	 
	 for (int j = 0; j < W; j++) {

	    int X;
	    cin >> X;

	    if (X >= N) {
	       int cur = p * N;
	       if (cur < cost) {
		  cost = cur;
	       }
	    }
	 }
      }

      if (cost == B+1) {
	 cout << "stay home\n";
      } else {
	 cout << cost << endl;
      }
   }
}
