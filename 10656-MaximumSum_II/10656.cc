/*
  Solution for UVA problem 10656
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1597

     Compile : g++11 -std=c++11 -o 10656 10656.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : print everything that isnt a 0. If everything is a 0, print one zero
*/

#include <iostream>

using namespace std;

int main()
{
   // setup
   int n;
   while(cin >> n && n != 0)
   {      
      int input[1000];
      for(int i = 0; i < n; ++i)
	 cin >> input[i];

      int count = 0; // for keeping track if everything is non-zero
      int start = 0; // for keeping track of what i should start at
      while(start < n)
      {
	 if(input[start] != 0)
	 {
	    // loop until a non-zero occurs
	    cout << input[start];
	    start++;
	    break;
	 }

	 else
	    start++;
      }

      // continue printing anything non-zerp
      for(int i = start; i < n; ++i)
      {
	 if(input[i] != 0)
	 {
	    cout << " " << input[i];
	    count++;
	 }
      }

      // if everything was a zero, print one zero
      if(count == 0) cout << "0";
      cout << "\n";
   }
}
