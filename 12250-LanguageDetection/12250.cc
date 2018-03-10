#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

   int i = 1;
   map<string, string> m;
   
   m["HELLO"] = "ENGLISH";
   m["HOLA"] = "SPANISH";
   m["HALLO"] = "GERMAN";
   m["BONJOUR"] = "FRENCH";
   m["CIAO"] = "ITALIAN";
   m["ZDRAVSTVUJTE"] = "RUSSIAN";

   string s;
   while (cin >> s && s != "#") {

      cout << "Case " << i++ << ": ";
      if (m.find(s) == m.end()) {
	 cout << "UNKNOWN\n";
      } else {
	 cout << m[s] << endl;
      }
   }
   
}
