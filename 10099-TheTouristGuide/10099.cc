#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

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

      int find(UF uf[], int x) {             // for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};

class Edge {

   public:
      Edge(int i=-1, int j=-1, double weight=0) {
	 v1 = i;
	 v2 = j;
	 w = weight;
      }
      bool operator<(const Edge& e) const { return w > e.w; }

      int v1, v2;          /* two endpoints of edge                */
      double w;            /* weight, can be double instead of int */
};


int main() {

   int n, m;
   int CASE = 1;

   while (cin >> n >> m && (n || m)) {

      UnionFind u(n+1);
      vector<Edge> EdgeList;

      for (int i = 0; i < m; i++) {

	 int x, y, w;
	 cin >> x >> y >> w;

	 Edge e(x, y, w-1);

	 EdgeList.push_back(e);
      }

      sort (EdgeList.begin(), EdgeList.end());


      int start, end, num, max;
      cin >> start >> end >> num;
      
      for (int i = 0; i < m; i++) {
	 
	 Edge e = EdgeList[i];
	 u.merge(e.v1, e.v2);

	 if (u.find(start) == u.find(end)) {
	    max = e.w;
	    break;
	 }
      }

      cout << "Scenario #" << CASE++ << endl
	   << "Minimum Number of Trips = "
	   << (max+num-1) / max << endl << endl;
   }
}
