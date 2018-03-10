#include <iostream>

using namespace std;

int main() {

   int N;
   cin >> N;

   while (N--) {

      int x;
      cin >> x;

      int ans = (x * 567);
      ans /= 9;
      ans += 7492;
      ans *= 235;
      ans /= 47;
      ans -= 498;

      ans = ans % 100;
      ans /= 10;

      if (ans < 0) {
	 ans *= -1;
      }
      
      cout << ans << endl;
   }
}
