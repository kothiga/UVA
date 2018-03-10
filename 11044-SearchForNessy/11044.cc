#include <iostream>

using namespace std;

int main() {

   int N;
   cin >> N;
   
   while (N--) {
      
      int x, y;
      cin >> x >> y;

      int count = 0;
      
      for (int i = 1; i < x-1; i+=3) {
	 for (int j = 1; j < y-1; j+=3) {
	    count++;
	 }
      }
      cout << count << endl; 
   }
}
