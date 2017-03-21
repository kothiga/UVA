/*
  Solution for UVA Problem 612 and
               ACM-ICPC North American - East Central NA
                    Regionals 1998 Problem 5414
  https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&c
ategory=494&page=show_problem&problem=3415

     Compile : g++11 -std=c++11 -o 5414 5414.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : Sort the dna sequences based on unsortedness
*/


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct DNA
{
   int ts;         // time stamp
   int val;        // unsortedness
   string strand;  // the sequence
   
   // overload for the sort
   bool operator < (const DNA& right) const
   {
      // if theres a tie
      // compare the time stamp
      if(this->val == right.val)
	 return this->ts < right.ts;
      else
	 // else do the regular comparason
	 return this->val < right.val;
   }
};

int findVal(string seq, int n)
{
   int val = 0;

   for(int i = 0; i < n-1; i++)
      for(int j = i+1; j < n; j++)
	 if(seq[i] > seq[j])
	    val++;
   
   return val;
}

int main()
{
   // setup
   int DATASETS;
   cin >> DATASETS;
   while(DATASETS--)
   {
      int n, m;
      DNA seq[100];
      cin >> n >> m;

      for(int i = 0; i < m; i++)
      {
	 cin >> seq[i].strand;
	 seq[i].ts = i;
	 seq[i].val = findVal(seq[i].strand, n);
      }

      // sort the array of DNA structs
      sort(seq, seq+m);

      // output
      for(int i = 0; i < m; i++)
	 cout << seq[i].strand << "\n";
      
      if(DATASETS) cout << "\n";
   }
}
