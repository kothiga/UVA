#include <iostream>

using namespace std;

int main() {

   int N;

   while (cin >> N && N) {

      int x, y;
      cin >> x >> y;
      
      while (N--) {

	 int px, py;
	 cin >> px >> py;

	 if (px == x || py == y) {
	    cout << "divisa\n";
	 } else if (px > x && py > y) {
	    cout << "NE\n";
	 } else if (px > x && py < y) {
	    cout << "SE\n";
	 } else if (px < x && py > y) {
	    cout << "NO\n";
	 } else {
	    cout << "SO\n";
	 }
      }
   }
}
