#include <iostream>
#include <list>
#include <cassert>

using namespace std;

const int MAX_NODE = 210;
int MAX = 0;

void clear_graph(int graph[MAX_NODE][MAX_NODE], int n)
{
   MAX = 0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	 graph[i][j] = 0;
      }
   }
}

void push(int graph[MAX_NODE][MAX_NODE], int flow[MAX_NODE][MAX_NODE],
	  int e[], int u, int v)
{
   int cf = graph[u][v] - flow[u][v];
   int d = (e[u] < cf) ? e[u] : cf;
   flow[u][v] += d;
   flow[v][u] = -flow[u][v];
   e[u] -= d;
   e[v] += d;
}

void relabel(int graph[MAX_NODE][MAX_NODE], int flow[MAX_NODE][MAX_NODE],
	     int n, int h[], int u)
{
   h[u] = -1;
   for (int v = 0; v < n; v++) {
      if (graph[u][v] - flow[u][v] > 0 &&
	  (h[u] == -1 || 1 + h[v] < h[u])) {
	 h[u] = 1 + h[v];
      }
   }

   assert(h[u] >= 0);
}

void discharge(int graph[MAX_NODE][MAX_NODE], int flow[MAX_NODE][MAX_NODE],
	       int n, int e[], int h[], list<int>& NU, 
	       list<int>::iterator &current, int u)
{
   while (e[u] > 0) {
      if (current == NU.end()) {
	 relabel(graph, flow, n, h, u);
	 current = NU.begin();
      } else {
	 int v = *current;
	 if (graph[u][v] - flow[u][v] > 0 && h[u] == h[v] + 1) {
	    push(graph, flow, e, u, v);
	 } else {
	    ++current;
	 }
      }
   }
}

int network_flow(int graph[MAX_NODE][MAX_NODE], int flow[MAX_NODE][MAX_NODE], 
		 int n, int s, int t)
{
   int e[MAX_NODE], h[MAX_NODE];
   int u, v, oh;
   list<int> N[MAX_NODE], L;
   list<int>::iterator current[MAX_NODE], p;

   for (u = 0; u < n; u++) {
      h[u] = e[u] = 0;
   }
   for (u = 0; u < n; u++) {
      for (v = 0; v < n; v++) {
	 flow[u][v] = 0;
	 if (graph[u][v] > 0 || graph[v][u] > 0) {
	    N[u].push_front(v);
	 }
      }
   }
   h[s] = n;
   for (u = 0; u < n; u++) {
      if (graph[s][u] > 0) {
	 e[u] = flow[s][u] = graph[s][u];
	 e[s] += flow[u][s] = -graph[s][u];
      }
      if (u != s && u != t) {
	 L.push_front(u);
      }
      current[u] = N[u].begin();
   }

   p = L.begin();
   while (p != L.end()) {
      u = *p;
      oh = h[u];
      discharge(graph, flow, n, e, h, N[u], current[u], u);
      if (h[u] > oh) {
	 L.erase(p);
	 L.push_front(u);
	 p = L.begin();
      }
      ++p;
   }
  
   int maxflow = 0;
   for (u = 0; u < n; u++) {
      if (flow[s][u] > 0) {
	 maxflow += flow[s][u];
      }
   }
   return maxflow;
}

void print_flow(int flow[MAX_NODE][MAX_NODE], int n)
{
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	 if (flow[i][j] > 0) {
	    cout << i << " -> " << j << ": " << flow[i][j] << endl;
	 }
      }
   }
}

int main() {

   int graph[MAX_NODE][MAX_NODE];
   int s = 208, t = 209;
   int n, m, b, d, u, v, c;
   int flow[MAX_NODE][MAX_NODE];
   int maxflow;
   
   while (cin >> n) {

      clear_graph(graph, MAX_NODE);

      // set up a facilities max capacity
      for (int i = 0; i < n; i++) {
	 cin >> c; 
	 graph[(i*2)][(i*2)+1] = c;
      }

      // set up the connections between facilities
      cin >> m;
      for (int i = 0; i < m; i++) {
	 cin >> u >> v >> c; u--; v--; 
	 graph[(u*2)+1][(v*2)] = c;
	 MAX += c;
      }

      // get the number of
      // paths from start
      // and end
      cin >> b >> d;

      // make connections between start
      // to facilities
      for (int i = 0; i < b; i++) {
	 int x; cin >> x; x--;
	 graph[s][(x*2)] = MAX;
      }

      // make connections between
      // facilities to target
      for (int i = 0; i < d; i++) {
	 int x; cin >> x; x--;
	 graph[(x*2)+1][t] = MAX;
      }
      
      maxflow = network_flow(graph, flow, MAX_NODE, s, t);
      cout << maxflow << endl;
   }
}
