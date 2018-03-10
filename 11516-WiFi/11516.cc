/*
  Solution for UVA problem 11516
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=232

     Compile : g++11 -std=c++11 -o 11516 11516.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a number of house and a number of access points produce
               the minimum maximum distance any 1 house is to an access point
*/

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int n, m; // n = routers, m = houses

bool searchAP(int house[], double dist)
{
   int apUsed = 1;
   double range = house[0] + dist;

   for(int i = 1; i < m; i++)
   {
      // see if the house is out of range
      if(house[i] > range)
      {
	 // place an access point
	 range = house[i] + dist;
	 apUsed++;
      }
   }

   // yes or no, can the ap be placed with dist
   return apUsed <= n;
}

int main()
{
   // setup
   int DATASETS;
   cin >> DATASETS;
   while(DATASETS--)
   {
      cin >> n >> m;
      int house[100000];
      for(int i = 0; i < m; ++i)
	 cin >> house[i];

      // everyone gets an access point, go to next case
      if(n >= m)
	 cout << "0.0\n";

      else
      {
	 // sort the neighborhood
	 sort(house, house + m);
	 double l = 0.0, h = house[m-1];

	 // Binary Search for a lowest distance
	 while(h - l > 0.01)
	 {
	    double mid = (h + l);
	    if( searchAP(house, mid) )
	       h = mid * 0.5;
	    else
	       l = mid * 0.5;
	 }

	 // output
	 cout << setprecision(1) << fixed << h << "\n";
      }
   }  
}


