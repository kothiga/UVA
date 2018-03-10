#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {

   string ans1 = " -- is not a palindrome.\n\n";
   string ans2 = " -- is a regular palindrome.\n\n";
   string ans3 = " -- is a mirrored string.\n\n";
   string ans4 = " -- is a mirrored palindrome.\n\n";


   map<char, char> pal;
   pal['A'] = 'A';   pal['M'] = 'M';   pal['Y'] = 'Y';
   pal['B'] = ' ';   pal['N'] = ' ';   pal['Z'] = '5';
   pal['C'] = ' ';   pal['O'] = 'O';   pal['1'] = '1';
   pal['D'] = ' ';   pal['P'] = ' ';   pal['2'] = 'S';
   pal['E'] = '3';   pal['Q'] = ' ';   pal['3'] = 'E';
   pal['F'] = ' ';   pal['R'] = ' ';   pal['4'] = ' ';
   pal['G'] = ' ';   pal['S'] = '2';   pal['5'] = 'Z';
   pal['H'] = 'H';   pal['T'] = 'T';   pal['6'] = ' ';
   pal['I'] = 'I';   pal['U'] = 'U';   pal['7'] = ' ';
   pal['J'] = 'L';   pal['V'] = 'V';   pal['8'] = '8';
   pal['K'] = ' ';   pal['W'] = 'W';   pal['9'] = ' ';
   pal['L'] = 'J';   pal['X'] = 'X';

   char mir[13] = {'A', 'H', 'I', 'M', 'O', 'T', 'U',
		   'V', 'W', 'X', 'Y', '1', '8' };
   
   string s;
   while (cin >> s) {
      
      bool mirror = true;
      bool palin = true;

      // CHECK PALINDROME & MIRROR
      for (int i = 0; i < (s.length()/2); i++) {
	 if (s[i] != s[s.length()-i-1]) {
	    palin = false;
	 }

	 if (s[i] != pal[s[s.length()-i-1]]
	     && s[s.length()-i-1] != pal[s[i]]) {
	    mirror = false;
	 }
      }

      // CHECK MIDDLE LETTER
      bool mid = true;
      if (s.length() % 2) {
	 mid = false;
	 for (int i = 0; i < 13; i++) {
	    if (s[s.length()/2] == mir[i]) {
	       mid = true;
	    }
	 }
      }

      if (palin && mirror && mid) {
	 cout << s << ans4;
      } else if (palin) {
	 cout << s << ans2;
      } else if (mirror && mid) {
	 cout << s << ans3;
      } else {
	 cout << s << ans1;
      }
   }
      

}
