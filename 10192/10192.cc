/*
  Solution for UVA problem 10192
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1133

     Compile : g++11 -std=c++11 -o 10192 10192.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : Find the max number of cities that you can visit
               given two sets of possible order
               (Longest Common Subsequence)
*/


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_LEN = 100;

int LCS(string A, int n, string B, int m)
{
  int L[MAX_LEN+1][MAX_LEN+1];
  int i, j;
  
  for (i = n; i >= 0; i--)
     for (j = m; j >= 0; j--)
     {
	if (i == n || j == m) L[i][j] = 0;
	else if (A[i] == B[j]) L[i][j] = 1 + L[i+1][j+1];
	else L[i][j] = max(L[i+1][j], L[i][j+1]);
     }
  
  return L[0][0];
}

int main()
{
   // setup
   int CASE = 1;
   while(true)
   {
      int mLen, dLen, vis;
      string mom, dad;

      getline(cin, mom);
      if(mom == "#") break;
      getline(cin, dad);
      mLen = mom.length(); dLen = dad.length();

      // how long is the LCS
      vis = LCS(mom, mLen, dad, dLen);

      // output
      cout << "Case #" << CASE++
	   << ": you can visit at most " << vis
	   << " cities.\n";
   }
}
