#include <iostream>
#include <cctype>
#include <string>

using namespace std;

const int MAX = 10;
const char vow[MAX] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

string mod(string word) {

   string s = "";

   for (int i = 0; i < MAX; i++) {
      if (word[0] == vow[i]) {

	 s = word;
	 s += "ay";

	 return s;
      }
   }
   
   int len = word.length();
   for (int i = 1; i < len; i++) {
      s += word[i];
   }
   s += word[0];
   s += "ay";
   return s;
}


int main() {

   string s;
   while (getline(cin, s)) {

      int len = s.length();

      string word = "";
      for (int i = 0; i < len; i++) {

	 if (isalpha(s[i])) {

	    word += s[i];

	 } else {

	    if (word != "") 
	       cout << mod(word);
	    cout << s[i];
	    word = "";

	 }
      }

      
      if (word != "") {
	 cout << mod(word);
      }
      
      cout << endl;
   }

   return 0;
}
