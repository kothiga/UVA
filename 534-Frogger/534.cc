#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
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
      bool operator<(const Edge& e) const { return w < e.w; }

      int v1, v2;          /* two endpoints of edge                */
      double w;            /* weight, can be double instead of int */
};

double euclid(double x1, double y1, double x2, double y2) {
   return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)); 
}

const int MAX = 1001;

int main() {

   int CASE = 1;
   
   int N;
   int pointsX[MAX];
   int pointsY[MAX];
   
   while (cin >> N && N) {

      // get all points
      for (int i = 0; i < N; i++) {
	 int x, y;
	 cin >> x >> y;
	 
	 pointsX[i] = x;
	 pointsY[i] = y;
      }

      // build the edge list
      vector<Edge> EdgeList;
      
      for (int i = 0; i < N; i++) {
	 
	 double x1, y1;
	 x1 = pointsX[i];
	 y1 = pointsY[i];

	 for (int j = i+1; j < N; j++) {

	    double x2, y2;
	    x2 = pointsX[j];
	    y2 = pointsY[j];

	    double w = euclid (x1, y1, x2, y2);

	    Edge e(i, j, w);

	    EdgeList.push_back(e);
	 }
      }

      // sort the edges
      sort(EdgeList.begin(), EdgeList.end());

      // search for the path
      UnionFind u(N);

      double w;
      for (unsigned int i = 0; i < EdgeList.size(); i++) {

	 Edge e = EdgeList[i];
	 u.merge(e.v1, e.v2);

	 if (u.find(0) == u.find(1)) {
	    w = e.w;
	    break;
	 }
      }

      cout << "Scenario #" << CASE++ << endl
	   << "Frog Distance = " << setprecision(3) << fixed
	   << sqrt(w) << endl << endl;
     
   }
}
