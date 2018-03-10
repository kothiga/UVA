/*
  Solution for UVA problem 11228
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2169

     Compile : g++11 -std=c++11 -o 11228 11228.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : give coordinates of cities, build an mst
               which represents connecting roads and railways
*/


#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX_R = 40001;
const int MAX_N = 1001;

double states = 0, road = 0, railway = 0;

class UnionFind
{
   struct UF { int p; int rank; };

public:
   UnionFind(int n)
   { // constructor
      howMany = n;
      uf = new UF[howMany];
      for (int i = 0; i < howMany; i++)
      { uf[i].p = i; uf[i].rank = 0; }
   }

   ~UnionFind(){ delete[] uf; }

   int find(int x) { return find(uf,x); }  
   bool merge(int x, int y)
   {
      int res1, res2;
      res1 = find(uf, x);
      res2 = find(uf, y);
      if (res1 != res2)
      {
	 if (uf[res1].rank > uf[res2].rank){ uf[res2].p = res1; }
	 else
	 { uf[res1].p = res2; if (uf[res1].rank == uf[res2].rank){ uf[res2].rank++; } }
	 return true;
      } return false;
   }
      
private:
   int howMany;
   UF* uf;

   int find(UF uf[], int x)
   { // for internal use
      if (uf[x].p != x){ uf[x].p = find(uf, uf[x].p); }
      return uf[x].p;
   }
};

class Edge
{
public:
   Edge(int i=-1, int j=-1, double weight=0)
   { v1 = i; v2 = j; w = weight; }
   
   bool operator<(const Edge& e) const { return w < e.w; }

   int v1, v2; /* two endpoints of edge                */
   double w;   /* weight, can be double instead of int */
};

void mst(int n, int r, int m, Edge elist[], int index[])
{
   // used for kruskal's algorithm
   UnionFind uf(n);

   sort(elist, elist+m);

   int size = 0;
   for (int i = 0; i < m && size < n-1; i++)
   {
      int c1 = uf.find(elist[i].v1);
      int c2 = uf.find(elist[i].v2);
    
      if (c1 != c2)
      {
	 index[size++] = i;

	 // if the weight between two
	 // cities is above the given
	 // threshold, they are in
	 // different states
	 if(elist[i].w >= r)
	 {
	    // railways connect states
	    states++;
	    railway += elist[i].w;
	 }
      
	 else
	    // roads connect cities
	    road += elist[i].w;

	 // join these nodes
	 uf.merge(c1, c2);
      }
   }
}

int main()
{
   // set up
   int DATASETS, CASE = 1;
   cin >> DATASETS;
   while(DATASETS--)
   {
      // city, threshold
      int n, r;
      cin >> n >> r;

      double x[MAX_N];
      double y[MAX_N];

      for(int i = 0; i < n; i++)
	 cin >> x[i] >> y[i];

      Edge* elist = new Edge[n*n];
      int k = 0;
      int index[MAX_N];

      // create an edge list that connects
      // every node to every node with
      // the weight being the hypotenuse
      // of the difference of the x, and y axises
      for(int i = 0; i < n; i++)
	 for(int j = 0; j < n; j++)
	    elist[k++] = Edge(i, j, hypot(x[i]-x[j], y[i]-y[j]));

      // init these (theres always atleast 1 state)
      states = 1; road = 0; railway = 0;

      // build the mst and set
      // the global variables
      mst(n, r, k, elist, index);

      // output
      cout << "Case #" << CASE << ": "
	   << states << " "
	   << round(road) << " "
	   << round(railway) << "\n";
      CASE++;      
   }
}
