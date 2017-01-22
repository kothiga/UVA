/*
  Solution for UVA problem 10189
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1130

     Compile : g++11 -std=c++11 -o 10189 10189.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a 2D field, print the amount of mines in proximity for each index
*/

#include <iostream>

using namespace std;

// used for incrementing numbers around mines
const int scanX[8] {-1, 0, 1, -1, 1, -1, 0, 1};
const int scanY[8] {-1, -1, -1, 0, 0, 1, 1, 1};

int main()
{
  // set up
  int fieldNum = 0;
  int n, m;
  while(cin >> n >> m && n && m)
    {
      // for printing empty line between
      if(fieldNum != 0) cout << "\n";
      
      // make n and m 2 bigger for buffer area on search
      n += 2;
      m += 2;

      // declare 2D char array
      char Minesweep[102][102];

      // read in initial field
      for(int i = 1; i < n-1; ++i)
	for(int j = 1; j < m-1; ++j)
	  {
	    cin >> Minesweep[i][j];

	    // set any non-mines to be 0
	    // makes the next part easier
	    if(Minesweep[i][j] != '*')
	      Minesweep[i][j] = '0';
	  }

      // scan through the field for mines and inc surrounging
      for(int i = 1; i < n-1; ++i)
	for(int j = 1; j < m-1; ++j)
	  {
	    // do work
	    if(Minesweep[i][j] == '*')
	      {
		// use the scanning array
		for(int k = 0; k < 8; ++k)
		  {
		    // if the index is not a mine, increment
		    if(Minesweep[i + scanX[k]][j + scanY[k]] != '*')
		      Minesweep[i + scanX[k]][j + scanY[k]]++;
		    // this works because an index character will never be greator than 8
		  }
	      }
	  }

      // output
      fieldNum++;
      cout << "Field #" << fieldNum << ":\n";
      for(int i = 1; i < n-1; ++i)
	{
	  for(int j = 1; j < m-1; ++j)
	    cout << Minesweep[i][j];
	  cout << "\n";
	}   
    }
}
