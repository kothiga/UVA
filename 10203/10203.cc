/*
  Solution for UVA problem 10203
  https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1144

     Compile : g++ -std=c++11 -o 10203 10203.cc -Wall
  Written by : Austin Kothig
    Semester : FALL 2017
     Problem : find how long it takes for a snow plow
               to plow a city
*/


#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

   int DATASETS;
   cin >> DATASETS; cin.ignore();

   // first empty line
   string str;
   getline(cin,str);
   while (DATASETS--) {
      // coordinates for the hanger
      getline(cin,str);
      double time = 0;
      while (getline(cin,str) && str != "") {
	 // pull apart the string
	 istringstream ss(str);
	 double x1, y1, x2, y2, d;
	 ss >> x1 >> y1 >> x2 >> y2;
	 d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
	 d = sqrt(d);
	 time += 2*(d / 333.333);
      }

      int t = round(time);
      
      // output
      int hr = t / 60;
      int min = t % 60;
      
      cout << hr << ":" << setfill('0') << setw(2) << min << endl;
      if(DATASETS) cout << endl;
   }
}
