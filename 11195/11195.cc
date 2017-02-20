/*
  Solution for UVA problem 11195
  https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2136
  
     Compile : g++11 -std=c++11 -o 11195 11195.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given an n, find the number of ways you can place n queens on an
               n by n chess board, where some spaces a queen may not be allowed
*/


#include <iostream>
#include <bitset>

using namespace std;

char board[15][15];
bitset<30> rw, // for checking if a row can contain a queen
           ld, // for checking if the left diagonals contain a queen
           rd; // for checking if the right diagonals contain a queen
int count;
void recurBackTrack(int, int);

int main()
{
   // set up
   int n;
   int caseNum = 0;
   while(cin >> n && n)
   { 
      for(int i = 0; i < n; ++i)
	 for(int j = 0; j < n; ++j)
	    cin >> board[i][j];

      // reset globals
      count = 0;
      rw.reset();
      ld.reset();
      rd.reset();

      // count the number of
      // successful cases
      recurBackTrack(n, 0);      

      // output
      caseNum++;
      cout << "Case " << caseNum << ": " << count << "\n";
   }
}

void recurBackTrack(int n, int current)
{
   // the current was able to make it to n
   if(current == n){ count++; return;}

   // for all other placements
   for(int i = 0; i < n; ++i)
   {
      if(board[i][current] != '*' && // if the current space is not a *
	 !rw[i] &&                   // row has no queen
	 !ld[i - current + n - 1] && // left diagonal has no queen
	 !rd[i + current])           // right diagonal has no queen
      {
	 // then add a queen at these positions
	 rw[i] = true;
	 ld[i - current + n - 1] = true;
	 rd[i + current] = true;

	 // check the next colomn
	 recurBackTrack(n, current+1);

	 // set these back to false for the next recursion
	 rw[i] = false;
	 ld[i - current + n - 1] = false;
	 rd[i + current] = false;
	 
      }
   } 
}
