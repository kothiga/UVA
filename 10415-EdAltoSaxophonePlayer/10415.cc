/*
  Solution for UVA problem 10415
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1356

     Compile : g++11 -std=c++11 -o 10415 10415.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given an input of notes, print the number of times
               a finger has to be pressed down. If a finger is already
               pressing, it does not need to repress
*/

#include <iostream>
#include <string>

using namespace std;

const int fingers[14][10]{
  //          fingers
  //1  2  3  4  5  6  7  8  9  10
  { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 }, // A
  { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, // B
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, // C
  { 1, 1, 1, 1, 0, 0, 1, 1, 1, 0 }, // D
  { 1, 1, 1, 1, 0, 0, 1, 1, 0, 0 }, // E
  { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 }, // F
  { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 }, // G   notes
  { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 }, // a
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, // b
  { 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 }, // c
  { 0, 1, 1, 1, 0, 0, 1, 1, 1, 0 }, // d
  { 0, 1, 1, 1, 0, 0, 1, 1, 0, 0 }, // e
  { 0, 1, 1, 1, 0, 0, 1, 0, 0, 0 }, // f
  { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 }  // g
};
    
int letterToIndex(char);

int main()
{
  // set up
  int n;
  cin >> n;
  cin.ignore();
  while(n--)
    {
      // set up for inscope
      int fingerPress[10]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
      bool currentPress[10]{ false, false, false, false, false, false, false, false, false, false };
      string notes;
      getline(cin, notes); // because some lines can have 'no notes'

      // while there are notes to do work on
      for(unsigned int i = 0; i < notes.length(); ++i)
	{
	  // get index of the current note
	  int index = letterToIndex(notes[i]);

	  // count the number of times the note is pressed
	  for(int j = 0; j < 10; ++j)
	    {
	      // if the note requires pushing
	      if(fingers[index][j] == 1)
		{
		  // if the finger is not already pushing
		  if(!currentPress[j])
		    {
		      // press with the finger and add it
		      currentPress[j] = true;
		      fingerPress[j] += 1;
		    }
		}

	      // note requires no pushing
	      else
		currentPress[j] = false;
	    }
	}

      // output
      for(int i = 0; i < 9; ++i)
	cout << fingerPress[i] << " ";
      cout << fingerPress[9] << "\n";
    }
}

// fancy character manupulation
int letterToIndex(char c)
{
  // a thru g
  if((c-'0') >= 49)
    return (c-'0') - 42;

  // A thru G
  return (c-'0') - 17;
}
