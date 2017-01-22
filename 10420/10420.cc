/*
  Solution for UVA problem 10420
  https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1361

     Compile : g++11 -std=c++11 -o 10420 10420.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : keep track of the number of Don Giovanni's lovers countries
               and print out how many were in each country
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
  int n; 
  while(cin >> n)
    {
      // declare a map of strings and ints
      map<string, int> lovers;
      for(int i = 0; i < n; ++i)
	{
	  string country, s;

	  // get the name of the country
	  cin >> country;

	  // get the rest of the line and do nothing with it
	  getline(cin, s);

	  // increment the number of lovers in said country
	  lovers[country]++;
	}

      // print the map
      for(map<string, int>::iterator i = lovers.begin(); i != lovers.end(); ++i)
	  cout << i->first << " " << i->second << '\n';
    }
}
