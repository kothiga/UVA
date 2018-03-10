/*
  Solution for UVA problem 116
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=52

     Compile : g++11 -std=c++11 -o 116 116.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : Print the shortest-lexicographical path
               accross a board and its total cost
*/

#include <iostream>

using namespace std;

int row, column;
int board[10][100];
int dpmat[10][100];

int buildDP(int x, int y)
{
    // if we are at the last column on the board
    if(y+1 == column) return dpmat[x][y] = board[x][y];

    // if this segment has already been seen
    if(dpmat[x][y] != 30001) return dpmat[x][y];

    // return the minimum of the 3 different traversals and store its sum
    return dpmat[x][y] = board[x][y] + min( buildDP((row + x + 1) % row, y + 1),
				       min( buildDP(x, y + 1),
				            buildDP((row + x - 1) % row, y + 1))); 
}

int main()
{
    while(cin >> row >> column)
    {
	// set up
	for(int i = 0; i < row; ++i)
	    for(int j = 0; j < column; ++j)
	    {
		cin >> board[i][j];
		dpmat[i][j] = 30001;
		// largest possible dp matrix value is 30000
	    }

	// build the dp matrix
	for(int i = 0; i < row; ++i)
	    dpmat[i][0] = buildDP(i, 0);

	// find the starting position
	int loIndex = 0;
	for(int i = 1; i < row; ++i)
	    if(dpmat[loIndex][0] > dpmat[i][0])
		loIndex = i;

	// print the first and grab the weight
	int total = dpmat[loIndex][0];
	cout << loIndex+1;

	// traverse and output
	for(int j = 1; j < column; ++j)
	{
	    int prevL = loIndex;
	    
	    // i = -1
	    loIndex = (row + prevL - 1) % row;

	    // i = 0 and i = 1
	    for(int i = 0; i < 2; ++i)
	    {
		// change the loIndex value if a smaller value
		// has been found, or if the values are equal
		// and if the new index is strictly smaller
		int index = (row + prevL + i) % row;
		if(dpmat[loIndex][j] > dpmat[index][j] ||
		   (dpmat[loIndex][j] == dpmat[index][j] && loIndex > index))
		    loIndex = index;
	    }
	    cout << " " << loIndex+1;
	}
	cout << "\n" << total << "\n";     
    }	
}
