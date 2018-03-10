/*
  Solution for UVA problem 11786
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=117&page=show_problem&problem=2886

     Compile : g++ -std=c++11 -o 11786 11786.cc -Wall
  Written by : Austin Kothig
    Semester : FALL 2017
     Problem : find out how much water is collected
*/


#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
   int DATASETS;
   cin >> DATASETS;
   while(DATASETS--) {
      string s; cin >> s;
      stack<int> m; int vol = 0;
      for (unsigned int i = 0; i < s.length(); i++) {
	 // decreasing
	 if (s[i] == '\\')
	    m.push(i);

	 // increasing
	 if (s[i] == '/' && !m.empty())
	 {
	    int cur = m.top(); m.pop();
	    vol += (i - cur);
	 }
      }
      cout << vol << endl;
   }
}
