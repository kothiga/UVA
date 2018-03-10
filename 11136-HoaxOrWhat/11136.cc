/*
  Solution for UVA problem 11136
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2077

     Compile : g++11 -std=c++11 -o 11136 11136.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a bunch of bills being added into an urn, take the largest and 
               smallest bill at the end of a day, and add the difference to a payout counter,
               then discard these two bills from the urn.
*/

#include <iostream>
#include <set>

using namespace std;

int main()
{
  // set up
   int n;
   while(cin >> n && n != 0) // loop until n == 0
   {
      multiset<int> urn;
      long long PAYOUT = 0;
      for(int DAYS = 0; DAYS < n; ++DAYS)
      {
	// get the number of bills for the day
	 int k;
	 cin >> k;
	 
	 for(int i = 0; i < k; ++i)
	 {
	   // add each bill from the day to the urn
	    int recp;
	    cin >> recp;
	    urn.insert(recp);
	 }

	 // get the largest and smallest bill in the urn
	 multiset<int>::iterator MIN = urn.begin(), MAX = urn.end();
	 MAX--;

	 // add the dif
	 PAYOUT += (*MAX - *MIN);

	 // remove the bills 
	 urn.erase(MAX);
	 urn.erase(MIN);

      }
      // output
      cout << PAYOUT << "\n";
   } 
}
