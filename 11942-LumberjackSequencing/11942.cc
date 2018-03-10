#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main () {

   int n;
   cin >> n; cin.ignore();


   cout << "Lumberjacks:\n";
   while (n--) {

      vector<int> v;

      string s;
      getline(cin, s);

      istringstream ss(s);

      int cur;
      while (ss >> cur) {
	 v.push_back(cur);
      }

      // determine order
      bool ordered = false;

      bool BR = false;
      for (int i = 1; i < v.size(); i++) {
	 if(v[i] < v[i-1]) {
	    BR = true;
	    break;
	 }
      }

      if (!BR) {
	 ordered = true;
      }
      
      BR = false;
       for (int i = 1; i < v.size(); i++) {
	 if(v[i] > v[i-1]) {
	    BR = true;
	    break;
	 }
       }
       
      if (!BR) {
	 ordered = true;
      }

      if (ordered) {
	 cout << "Ordered\n";
      } else {
	 cout << "Unordered\n";
      }
   }


}
