/*
  Solution for UVA problem 409
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=350

     Compile : g++11 -std=c++11 -o 409 409.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a set of k keywords, and e sentances, 
               return the sentance(s) that has the most keywords
*/

#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int main()
{
  // Set the first excuse set number
  int excuseSet = 1;
  int k, e;               // k = # of keywords // e = # of sentances //

  // while there is still input the receive
  while(cin >> k >> e)
    {
      // have a set for the key words for the find() function
      set<string> keyWords;
      
      for(int i = 0; i < k; ++i)
	{
	  string s;
	  cin >> s;

	  // make s a lower case string
	  for(unsigned int j = 0; j < s.length(); ++j)
	    s[j] = tolower(s[j]);

	  // insert a lower case version of s into the set
	  keyWords.insert(s);
	}

      // declare an array of size e
      string excu[e];

      for(int i = 0; i < e; ++i)
	{
	  // get the first word from the sentance
	  // (because getline was not working as intended)
	  cin >> excu[i];
	  string s;

	  // get the rest of the line
	  getline(cin, s);

	  // append it
	  excu[i] += s;
	  
	} // loop while there are still sentances
 
      // a counter array for each index of e
      int count[e];

      // for all index's of excu & count
      for(int i = 0; i < e; ++i)
	{
	  // istringstream to separate the ' '
	  istringstream iss(excu[i]);
	  string allS = "", currS;

	  // loop until iss is eol
	  while(iss >> currS)
	    {
	      // make the temporary currS all lowercase
	      for(unsigned int j = 0; j < currS.length(); ++j)
		{
		  // if the indecie is a punctuation
		  if(!isalpha(currS[j]))
		    currS[j] = ' ';

		  // set it to be lowercase
		  else 
		    currS[j] = tolower(currS[j]);
		}
	      
	      // append the edited word in the sentence
	      allS = allS + currS + " ";
	    }

	  // istringstream to separate the ' ' in the edited sentance
	  istringstream iss2(allS);

	  // set the count index to be 0
	  count[i] = 0;
	  
	  // count the keywords
	  while(iss2 >> currS)
	    {
	      // check if it is in the set
	      if(keyWords.find(currS) != keyWords.end())
		count[i]++;
	    }
	}

      // keep track of which index has the highest count
      int maxIndex = 0;

      // linear check for who has the largest count
      for(int i = 1; i < e; ++i)
	{
	  if(count[i] > count[maxIndex])
	    maxIndex = i;
	}

      // keep track of what the largest count is
      int maxValue = count[maxIndex];
      
      // output
      cout << "Excuse Set #" << excuseSet << '\n';
      excuseSet++;

      // print any index with the largest count
      for(int i = 0; i < e; ++i)
	{
	  if(count[i] == maxValue)
	    cout << excu[i] << '\n';
	}

      // delete the set
      keyWords.clear();

      cout << '\n';
    }

}
