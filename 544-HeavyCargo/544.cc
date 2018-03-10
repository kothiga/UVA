#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
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
      Edge(int i=-1, int j=-1, double weight=0) {
	 v1 = i;
	 v2 = j;
	 w = weight;
      }
      bool operator<(const Edge& e) const { return w > e.w; }

      int v1, v2;          /* two endpoints of edge                */
      double w;            /* weight, can be double instead of int */
};

const int MAXN = 201;
const int MAXR = 19901;

int main() {

   int CASE = 1;
   int N, R;

   while (cin >> N >> R && N && R) {

      int NODE = 0;
      map<string, int> m;
      m.clear();
      
      // build the edge list
      vector<Edge> EdgeList;
      
      for (int i = 0; i < R; i++) {

	 int p1, p2;
	 
	 string s1, s2;
	 double w;

	 cin >> s1 >> s2 >> w;

	 if (m.find(s1) == m.end()) {
	    m[s1] = NODE++;
	    p1 = m[s1];
	 } else {
	    p1 = m[s1];
	 } if (m.find(s2) == m.end()) {
	    m[s2] = NODE++;
	    p2 = m[s2];
	 } else {
	    p2 = m[s2];
	 }

	 Edge e(p1, p2, w);
	 EdgeList.push_back(e);
      }
      
      // sort the edges
      sort(EdgeList.begin(), EdgeList.end());

      // search for the path
      UnionFind u(N);

      string start, end;
      cin >> start >> end;

      int st, en;
      st = m[start];
      en = m[end];	 
      
      double w;
      for (unsigned int i = 0; i < EdgeList.size(); i++) {
	 
	 Edge e = EdgeList[i];
 
	 u.merge(e.v1, e.v2);
	 
	 if (u.find(st) == u.find(en)) {
	    w = e.w;
	    break;
	 }
      }
      cout << "Scenario #" << CASE++ << endl
	   << w << " tons\n\n";
   }
}
