/*
  Solution for UVA problem 10684
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1625

     Compile : g++11 -std=c++11 -o 10684 10684.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a sequence of 'gains', find the maximum
               possible gain
*/

#include <iostream>

using namespace std;

int streak[10001];

int vecsum(int v[], int n)
{
   // setup
   int start = 0;
   int end = n;
   int maxval = 0;
   int max_end = 0;
   int max_end_start, max_end_end;
   int i;

   // initialize an empty longest-length
   start = max_end_start = 0;
   end = max_end_end = -1;

   // linearly go through the sequence
   for (i = 0; i < n; i++)
   {
      if (v[i] + max_end >= 0)
      {
	 max_end = v[i] + max_end;
	 max_end_end = i;
      }

      else
      {
	 max_end_start = i+1;
	 max_end_end = -1;
	 max_end = 0;
      }

      if (maxval < max_end)
      {
	 start = max_end_start;
	 end = max_end_end;
	 maxval = max_end;
      }

      else if (maxval == max_end)
      {
	 if (max_end_end - max_end_start > end - start ||
	     (max_end_end - max_end_start == end - start &&
	      max_end_start < start))
	 {
	    start = max_end_start;
	    end = max_end_end;
	    maxval = max_end;
	 }
      }
   }
   return maxval;
}

int main()
{
   // setup
   int n;
   while(cin >> n && n != 0)
   {
      for(int i = 0; i < n; i++)
	 cin >> streak[i];

      // output
      int winningStreak = vecsum(streak, n);

      if(winningStreak > 0)
	 cout << "The maximum winning streak is " << winningStreak
	      << ".\n";
      else
	 cout << "Losing streak.\n";

   }
}
