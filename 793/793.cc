/*
  Solution for UVA problem 793
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=734

     Compile : g++11 -std=c++11 -o 793 793.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given the number of computers in a network, followed by an unknown number of inputs,
               either connect two computers, or check to see if they are connected, then 
               output the number of times the check returned true,false
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Howard Cheng's UnionFind class
// Methods : int find(int x) - returns the index of x in the Network
//           bool merge(int x, int y) - merges two nodes in the Network
class UnionFind
{
  struct UF { int p; int rank; };

public:
  UnionFind(int n) {          // constructor
    howMany = n;
    uf = new UF[howMany];
    for (int i = 0; i < howMany; i++) {
      uf[i].p = i;
      uf[i].rank = 0;
    }
  }

  ~UnionFind() {
    delete[] uf;
  }

  int find(int x) { return find(uf,x); }        // for client use
      
  bool merge(int x, int y) {
    int res1, res2;
    res1 = find(uf, x);
    res2 = find(uf, y);
    if (res1 != res2) {
      if (uf[res1].rank > uf[res2].rank) {
	uf[res2].p = res1;
      }
      else {
	uf[res1].p = res2;
	if (uf[res1].rank == uf[res2].rank) {
	  uf[res2].rank++;
	}
      }
      return true;
    }
    return false;
  }
      
private:
  int howMany;
  UF* uf;

  int find(UF uf[], int x) {     // recursive funcion for internal use
    if (uf[x].p != x) {
      uf[x].p = find(uf, uf[x].p);
    }
    return uf[x].p;
  }
};

int main()
{
  // set up
  int DATASETS;
  cin >> DATASETS;
  while(DATASETS--)
    {
      int numComp;
      cin >> numComp;
      cin.ignore();

      // Create a UnionFind object that will
      // keep track of connected nodes
      UnionFind Network(numComp+1);
      int right = 0, wrong = 0;
      string inputLine;
      cout << "here\n";
      while(getline(cin, inputLine))
	{
	  if(inputLine == "") break;
	 
	  istringstream iss(inputLine);
	  string type, ci, cj;
	  iss >> type >> ci >> cj;
	  
	  int i, j;
	  i = stoi(ci);
	  j = stoi(cj);
	  
	  // connect two computers
	  if(type == "c")
	    Network.merge(i, j);

	  // check if two computers are connected
	  else if(type == "q")
	    {
	      // if their indexes are the same,
	      // there is a connection
	      if(Network.find(i) == Network.find(j))
		right++;
	      else
		wrong++;
	    }

	}

      // output
      cout  << right << "," << wrong << "\n";
      if(DATASETS) cout << "\n";
	 
    }
}
