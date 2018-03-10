
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cassert>

using namespace std;

struct Edge;
typedef list<Edge>::iterator EdgeIter;

struct Edge {
   int to;
   int cap;
   int flow;
   bool is_real;
   EdgeIter partner;
  
   Edge(int t, int c, bool real = true)
      : to(t), cap(c), flow(0), is_real(real)
   {};

   int residual() const
   {
      return cap - flow;
   }
};

struct Graph {
   list<Edge> *nbr;
   int num_nodes;
   Graph(int n)
      : num_nodes(n)
   {
      nbr = new list<Edge>[num_nodes];
   }

   ~Graph()
   {
      delete[] nbr;
   }

   // note: this routine adds an edge to the graph with the specified capacity,
   // as well as a residual edge.  There is no check on duplicate edge, so it
   // is possible to add multiple edges (and residual edges) between two
   // vertices
   void add_edge(int u, int v, int cap)
   {
      nbr[u].push_front(Edge(v, cap));
      nbr[v].push_front(Edge(u, 0, false));
      nbr[v].begin()->partner = nbr[u].begin();
      nbr[u].begin()->partner = nbr[v].begin();
   }
};

void push_path(Graph &G, int s, int t, const vector<EdgeIter> &path, int flow)
{
   for (int i = 0; s != t; i++) {
      if (path[i]->is_real) {
	 path[i]->flow += flow;
	 path[i]->partner->cap += flow;
      } else {
	 path[i]->cap -= flow;
	 path[i]->partner->flow -= flow;
      }
      s = path[i]->to;
   }
}

// the path is stored in a peculiar way for efficiency: path[i] is the
// i-th edge taken in the path.
int augmenting_path(const Graph &G, int s, int t, vector<EdgeIter> &path,
		    vector<bool> &visited, int step = 0)
{
   if (s == t) {
      return -1;
   }
   for (EdgeIter it = G.nbr[s].begin(); it != G.nbr[s].end(); ++it) {
      int v = it->to;
      if (it->residual() > 0 && !visited[v]) {
	 path[step] = it;
	 visited[v] = true;
	 int flow = augmenting_path(G, v, t, path, visited, step+1);
	 if (flow == -1) {
	    return it->residual();
	 } else if (flow > 0) {
	    return min(flow, it->residual());
	 }
      }
   }
   return 0;
}

// note that the graph is modified
int network_flow(Graph &G, int s, int t)
{
   vector<bool> visited(G.num_nodes);
   vector<EdgeIter> path(G.num_nodes);
   int flow = 0, f;

   do {
      fill(visited.begin(), visited.end(), false);
      if ((f = augmenting_path(G, s, t, path, visited)) > 0) {
	 push_path(G, s, t, path, f);
	 flow += f;
      }
   } while (f > 0);
  
   return flow;
}

struct inp {
   int u, v, cap, cost, day;

   bool operator<(const inp& a) const {
      return cost < a.cost;
   }
};

int main() {

   int N, CASE = 1;
   cin >> N;
   
   int n, m, d, s = 318, t = 319, u, v,
      cap, cost, day, maxflow, maxCost;

   while (N--) {
      maxCost = 0;

      cin >> n >> d >> m;
      
      vector<inp> flights;

      for (int i = 0; i < m; i++) {
	 
	 cin >> u >> v >> cap >> cost >> day;
	 
	 inp x;
	 x.u = u-1; x.v = v-1; x.cap = cap;
	 x.cost = cost; x.day = day;

	 flights.push_back(x);

	 if (cost > maxCost) {
	    maxCost = cost;
	 }
      }

      sort (flights.begin(), flights.end());

      vector<int> partis;
      int sum = 0;
      for (int i = 0; i < n; i++) {
	 int x; cin >> x;
	 partis.push_back(x);
	 sum += x;
      }

      cout << maxCost << endl;
      
      // to a binary search
      // starting at max, to find
      // the lowest cost.
      int hi = maxCost;
      int mid = maxCost;
      int lo = 0;
      while (mid - lo > 0) {
	 
	 Graph G(32*10);

	 // set edges for waiting
	 for (int i = 0; i < n; i++) {
	    G.add_edge(s, i*10, sum);
	    for (int j = 1; j < d; j++) {
	       G.add_edge(i*10, (i*10)+j, sum);
	    }
	 }

	 // look for flights
	 for (int i = 0; i < flights.size(); i++) {
	    if (flights[i].cost > mid) { break; }

	    inp cur = flights[i];

	    G.add_edge((cur.u*10)+cur.day, (cur.v*10)+cur.day+1, cur.cap);
	 }

	 G.add_edge(((n-1)*10)+d, t, sum+10);

	 maxflow = network_flow(G, s, t);

	 cout << maxflow << " " << sum;

	 if (sum > maxflow) {
	    // could not be done

	    // if first exit
	    if (mid == maxCost) {
	       maxflow = -1;
	       break;
	    }

	    // update
	    mid = (mid+lo)/2;
	 } else {

	    if (mid == maxCost) {
	       mid = (hi+lo)/2;
	    } else {
	       mid = (mid+hi)/2;
	    }
	 }
      }
      
      
      cout << "Case #" << CASE++ << ": ";
      if (maxflow == -1) {
	 cout << "Impossible\n";
      } else {
	 cout << mid << endl;
      }

      
   }
}


