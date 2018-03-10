#include <iostream>
#include <algorithm>
#include <vector>
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
   Edge(int i=-1, int j=-1, int weight=0) {
      v1 = i;
      v2 = j;
      w = weight;
   }
   bool operator<(const Edge& e) const { return w < e.w; }

   int v1, v2;          /* two endpoints of edge                */
   int w;            /* weight, can be double instead of int */
};

int main() {

   int n, m;
   while (cin >> n >> m && (m || n)) {

      UnionFind u(n);
      vector<Edge> EdgeList;
      
      for (int i = 0; i < m; i++) {
	 int x, y, z;
	 cin >> x >> y >> z;
	 Edge e(x, y, z);
	 EdgeList.push_back(e);
      }

      sort(EdgeList.begin(), EdgeList.end());

      int total = 0;
      int max = 0;
      for (unsigned int i = 0; i < EdgeList.size(); i++) {
	 
	 Edge e = EdgeList[i];
	 max += e.w;
	 
	 if (u.find(e.v1) != u.find(e.v2)) {
	    total += e.w;
	    u.merge(e.v1, e.v2);
	 }
      }
      cout << max - total << endl;
   }
}
