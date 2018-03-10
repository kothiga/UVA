/*
  Solution for UVA problem 296
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=232

     Compile : g++11 -std=c++11 -o 296 296.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a number of guesses, return either
               the correct solution, indeterminate, or impossible
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stack>

using namespace std;

int main()
{
   // set up
   int DATASETS;
   cin >> DATASETS;
   while(DATASETS--)
   {
      int n;
      cin >> n;
      cin.ignore();
      int guess[10][6];
      for(int i = 0; i < n; i++)
      {
	 string input;
	 getline(cin, input);
	 guess[i][0] = input[0]-'0'; // pos1
	 guess[i][1] = input[1]-'0'; // pos2
	 guess[i][2] = input[2]-'0'; // pos3
	 guess[i][3] = input[3]-'0'; // pos4
	 guess[i][4] = input[5]-'0'; // correct placement
	 guess[i][5] = input[7]-'0'; // misplacement
      }

      // keep track of possible answers
      stack<int> answer;

      // for all num between 0000 -> 9999
      for(int i = 0; i < 10; i++)
	 for(int j = 0; j < 10; j++)
	    for(int k = 0; k < 10; k++)
	       for(int l = 0; l < 10; l++)
	       {
		  // start assuming it is possible
		  bool isPossible = true;
		    
		  // ask about correct placement
		  for(int m = 0; m < n; m++)
		  {
		     // keep track of correct places and misplaces
		     int correctPlace = 0, misplace = 0;

		     // table for checking
		     int checker[4] = { i, j, k, l };
			
		     // make a temp to do work on
		     int misTemp[4] = { guess[m][0], guess[m][1], guess[m][2], guess[m][3] };

		     // scan for num of correct places
		     for(int x = 0; x < 4; x++)
			if(guess[m][x] == checker[x]) correctPlace++;
			
		     // count the number of misplaced positions there are
		     // and mark it as -1 if it has been worked on already
		     for(int x = 0; x < 4; x++)
			for(int y = 0; y < 4; y++)
			   if(misTemp[x] == checker[y] && misTemp[x] != -1)
			   { misTemp[x] = -1; checker[y] = -1; misplace++; }

		     // remove any duplicates from misplace
		     misplace -= correctPlace;

		     // one of the conditions was not met i.e. not possible
		     if(correctPlace != guess[m][4] || misplace != guess[m][5])
			isPossible = false;
		  }

		  // add the current answer to the stack
		  if(isPossible)
		  {
		     int ans = (i*1000) + (j*100) + (k*10) + l;
		     answer.push(ans);		
		  }
	       }

      // output
      if(answer.empty())
	 cout << "impossible\n";

      else if(answer.size() > 1)
	 cout << "indeterminate\n";

      else
	 cout << setw(4) << setfill('0') << answer.top() << "\n";
   }
}
