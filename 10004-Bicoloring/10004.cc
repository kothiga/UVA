/*
  Solution for UVA problem 10004
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=945
  
     Compile : g++11 -std=c++11 -o 10004 10004.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a graph, distinguish whether it can
               be colored with 2 colors
*/


#include <iostream>
#include <stack>

using namespace std;

const int MAX_N = 200;

struct Node
{
   bool nbr[MAX_N]; 
   int color;
   bool visited;
};

void clear(Node graph[], int n)
{
   // set everything to a default
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < n; j++)
	 graph[i].nbr[j] = false;
       graph[i].color = 0;
       graph[i].visited = false;
   }
}

// used for getting
// the alternate color
int Color(int in)
{
   if(in == 1) return 2;
   return 1;
}

bool biColor(Node graph[], int n)
{
   // initialize the stack
   stack<int> s;
   s.push(0);

   // dfs
   while(!s.empty())
   {
      // init
      int cur = s.top(); s.pop();

      // if we have not been here
      if(!graph[cur].visited)
      {
	 // mark as visited
	 graph[cur].visited = true;

	 // scan through the neighbors
	 for(int i = 0; i < n; i++)
	 {
	    // if there is a connection
	    if(graph[cur].nbr[i])
	    {
	       // add to the stack
	       s.push(i);

	       // color it the alternate
	       // color of current
	       graph[i].color = Color(graph[cur].color);
	    }
	 }
      }
   }

   // check colors
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	 if(graph[i].nbr[j])
	 {
	    // exit if a neighbor has the same color
	    if(graph[i].color == graph[j].color && (i != j))
	       return false;
	 }

   // if reached this point
   // the graph is biColorable
   return true;  
}

int main()
{
   // set up
   int n;
   while(cin >> n && n != 0)
   {
      Node graph[MAX_N];
      clear(graph, n);
      int l;
      cin >> l;

      for(int i = 0; i < l; i++)
      {
	 int x, y;
	 cin >> x >> y;
	 graph[x].nbr[y] = true;	 
      }	    

      // output
      if(biColor(graph, n))
	 cout << "BICOLORABLE.\n";
      else
	 cout << "NOT BICOLORABLE.\n";
   }
}
