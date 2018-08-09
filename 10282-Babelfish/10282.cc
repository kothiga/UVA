#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

   unordered_map<string, string> dict;
   
   string str, word;
   while(getline(cin, str) && str != "") {

      istringstream ss(str);
      
      //-- new translation. add.	 
      string word, babel;
      ss >> word >> babel;

      dict[babel] = word;
   }

   
   while (cin >> word) {
      
      if (dict.find(word) == dict.end()) {
	 cout << "eh" << endl;
      } else {
	 cout << dict[word] << endl;
      }
   }

   
   
   return 0;
}
