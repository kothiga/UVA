#include <iostream>

using namespace std;

int main() {

   int N;
   int C = 1;
   while (cin >> N && N) {

      int x = 0;
      int y = 0;
      
      for (int i = 0; i < N; i++) {

	 int z;
	 cin >> z;

	 if (z == 0) {
	    y++;
	 } else {
	    x++;
	 }
      }

      int EB = x - y;
      cout << "Case " << C++ << ": " << EB << endl;
   }
}
