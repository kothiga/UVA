#include <iostream>

using namespace std;

int main() {

   int N;
   cin >> N;

   while (N--) {

      int n;
      cin >> n;

      int total = 0;

      while (n--) {

	 int si, na, ef;
	 cin >> si >> na >> ef;

	 total += (si * ef);
      }
      
      cout << total << endl;
   }
}
