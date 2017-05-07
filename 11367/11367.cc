/*
  Solution for UVA problem 11367
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2352

     Compile : g++11 -std=c++11 -o 11367 11367.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : Given a bunch of cities that each have different
               fuel costs, find the least cost efficient way to
               get from a starting city to a target city
*/


#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) { }
};
  
typedef vector<Edge>::iterator EdgeIter;

struct Graph
{
   vector<Edge> *nbr;
   int num_nodes;
   Graph(int n) : num_nodes(n)
   { nbr = new vector<Edge>[num_nodes]; }
   ~Graph() { delete[] nbr; }

   void add_edge(int u, int v, int weight)
   { nbr[u].push_back(Edge(v, weight)); }
};

int endnode;
const int MAX_C = 101;
const int MAX_N = 1000;
int dist[MAX_N][MAX_N];

/* Check Validity of from to end with fuelCap */
bool valid(int u, int v, int fuelCap)
{
   // start nodes
   int x = u / MAX_C;
   int y = v / MAX_C;
   
   // end fuel level
   int fl = v % MAX_C;
   
   return fl+dist[x][y] <= fuelCap;
}

/* assume that D and P have been allocated */
int dijkstra(const Graph &G, int fuelCap, int src, vector<int> &D)
{
  typedef pair<int,int> pii;

  int n = G.num_nodes;
  vector<bool> used(n, false);
  priority_queue<pii, vector<pii>,  greater<pii> > fringe;
  
  D.resize(n);
  fill(D.begin(), D.end(), -1);
  
  D[src] = 0;

  fringe.push(make_pair(D[src], src));

  while (!fringe.empty())
  {
     pii next = fringe.top();
     fringe.pop();
     int u = next.second;

     // if found, leave
     if(u == endnode) return D[endnode];

     // skip to next case
     if (used[u]) continue;
     used[u] = true;
     for (EdgeIter it = G.nbr[u].begin(); it != G.nbr[u].end(); ++it)
     {
	// get the information of next nbr
	int v = it->to;
	int weight = it->weight + next.first;
	
	// if used or fuel
	// purchased is above fuelCap
	if (used[v] || !valid(u, v, fuelCap)) continue;

	// update if this is better
	if (D[v] == -1 || weight < D[v])
	{
	   D[v] = weight;
	   fringe.push(make_pair(D[v], v));
	}
     }
  }
  return D[endnode];
}

int main()
{
   // setup
   int n, m, q;
   int FC[MAX_N];
   int MAX_NODES;   
   cin >> n >> m;

   Graph g(n * MAX_C);   

   for(int i = 0; i < n; i++)
      cin >> FC[i];

   for(int i = 0; i < m; i++)
   {
      // x = path from
      // y = path to
      // z = distance of
      int x, y, z;
      cin >> x >> y >> z;
      dist[x][y] = dist[y][x] = z;

      // for fuel states of city x(0) -> x(99)
      for(int j = 0; j < MAX_C-1; j++)
      {
	 // add edges of xcur -> xnext
	 g.add_edge(x*MAX_C+j, x*MAX_C+j+1, FC[x]);
	 g.add_edge(y*MAX_C+j, y*MAX_C+j+1, FC[y]);

	 if(j-z > -1)
	 {
	    // if the trip can be made
	    g.add_edge(x*MAX_C+j, y*MAX_C+j-z, 0);
	    g.add_edge(y*MAX_C+j, x*MAX_C+j-z, 0);
	 }
      }
   }

   // output
   cin >> q;
   while(q--)
   {
      int c, d, s, e;
      cin >> c >> s >> e;
      vector<int> D;
      endnode = e*MAX_C;
      d = dijkstra(g, c, s*MAX_C, D);
      if(d == -1)
	 cout << "impossible\n";
      else
	 cout << d << "\n";
   }
}
