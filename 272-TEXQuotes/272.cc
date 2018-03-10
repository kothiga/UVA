#include <iostream>
#include <string>

using namespace std;

int main() {

   string s;

   char c;
   bool last = true;
   
   while (getline(cin, s)) {
      
      for (int i = 0; i < s.length(); i++) {

	 c = s[i];
	 
	 if (c =='\"') {

	    if (last) {
	       cout << "``"; last = false;
	    } else {
	       cout << "''"; last = true;
	    }
	 } else {
	    cout << c;
	 }
      }
      cout << endl;
   }
}
