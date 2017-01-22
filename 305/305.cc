/*
  Solution for UVA problem 305
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=241

     Compile : g++11 -std=c++11 -o 305 305.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a k, there are k good guys and k bad guys standing in a circle,
               if every m'th person is killed, what is the m in which all good guys survive
*/

#include <iostream>

using namespace std;

bool Joseph(int k, int m);

int main()
{
  int k;
  // while cin is true and k != 0
  while(cin >> k && k)
    {
      // values generated from running the Joseph function for all k < 0 && k >= 14
      //int setM[14] {2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881, 13482720};
      // uncomment the above for uva submission
      
      // bool for searching
      bool found = false;

      // item searching 
      // prune search to start at k+1, as all values
      // up until k+1 will yeild false regardless
      int m = k;

      // search until m is found
      while(!found)
	{
	  // increment to next m (first search is k+1)
	  m++; 

	  // use Joseph solving function
	  found = Joseph(k, m);

	} // loop if the Joseph function returns false
      
      /*                                      un-comment this for uva submission
      // get the m
      int m = setM[k-1];
      */
      
      // m is found, and m is . . .
      cout << m << '\n';

    } // loop until input is 0

  return 0;
}

bool Joseph(int k, int m)
{
  // set n and the first killIndex
  int n = 2*k, killIndex = (m - 1) % n;

  // simulate the process of killing
  // there can be at most k people to die
  for(int i = 0; i < k; ++i)
    {
      // if the kill index is a number less than
      // k, a Good Guy has been killed
      if(killIndex < k) return false;

      // decrease n
      n--;

      // set next kill index
      killIndex = (killIndex + m - 1) % n;
    }

  // if the for loop ran successful k times, m is found
  return true;
}
