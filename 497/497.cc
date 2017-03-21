/*
  Solution for UVA problem 497
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=438

     Compile : g++11 -std=c++11 -o 497 497.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : find the most amount of missles that a missle
               defense system can protect against
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> longestSubSeq(vector<int> v, int &len)
{
   int n = v.size();
   vector<int> last(n+1), pos(n+1), pred(n), x(n);
   
   if (n == 0) { len = 0; return x; }

   last[1] = v[pos[1] = 0];

   for (int i = 1; i < n; i++)
   {
      // using lower bound prevents dup values
      int j = lower_bound(last.begin()+1,
			  last.begin()+len+1,
			  v[i]) - last.begin();
     
      pred[i] = (j-1 > 0) ? pos[j-1] : -1;
      last[j] = v[pos[j] = i];
      len = max(len, j);
   }

   int start = pos[len];
   for (int i = len-1; i >= 0; i--)
   {
      x[i] = v[start];
      start = pred[start];
   }
   return x;
}

int main()
{
   // setup
   int DATASETS;
   cin >> DATASETS;
   cin.ignore(); cin.ignore();
   while(DATASETS--)
   {
      string s;
      vector<int> v;
      while(getline(cin, s))
      {
	 if(s == "") break;
	 v.push_back(stoi(s));
      }

      // n gets returned by reference
      int n = 1;
      vector<int> x = longestSubSeq(v, n);

      // output
      cout << "Max hits: " << n << "\n";
      for(int i = 0; i < n; i++)
      	 cout << x[i] << "\n";
      if(DATASETS) cout << "\n";	 
   }
}
