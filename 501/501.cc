/*
  Solution for UVA problem 501
  https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=442

     Compile : g++11 -std=c++11 -o 501 501.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : maintain a sorted database, and retrieve the ith index when requested
               where i += 1 each time a request is called
*/

#include <iostream>
#include <set>

using namespace std;

int main()
{
   // set up
   int DATASETS;
   int addTransac[30000]; // only need to declare these once
   
   cin >> DATASETS;
   while(DATASETS--)
   {      
      // additional set up
      int ADDMAX, GETMAX;
      cin >> ADDMAX >> GETMAX;

      // get the add transactions
      for(int i = 0; i < ADDMAX; ++i)
	 cin >> addTransac[i];

      // output set up
      int currAdd = 0, currSize = 1;
      bool first = true;
      multiset<int> dataBase;
      dataBase.insert(addTransac[currAdd++]);
      multiset<int>::iterator dbIT = dataBase.begin();
      
      // while there are still transactions to get
      while(GETMAX--)
      {
	// get what the size will be for the next time a get request is
	 int currGet;
	 cin >> currGet;

	 // loop until the size of the database is greator than or
	 // equal to the currGet
	 while(currSize < currGet && currAdd < ADDMAX)
	 {
	   // when the current get trans is less than the size 
	   int val = addTransac[currAdd++];
	   dataBase.insert(val);
	   if(*dbIT > val) dbIT--;
	   currSize++; 
	 }

	 // used just once
	 if(first)
	   {
	     dbIT = dataBase.begin();
	     first = false;
	   }

	 else
	   dbIT++;
	 
	 cout << *dbIT << "\n";
	 
	 
      } 
      // printing between
      if(DATASETS != 0) cout << "\n";
   }
   return 0;
}
