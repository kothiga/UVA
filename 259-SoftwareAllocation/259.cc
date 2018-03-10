#include <iostream>
#include <cassert>
#include <list>
#include <string>
#include <sstream>

using namespace std;

const int MAX_NODE = 50;


void clear_graph(int graph[MAX_NODE][MAX_NODE], int n)
{
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

   string str;

   int graph[MAX_NODE][MAX_NODE];
   int s = 48, t = 49;
   int flow[MAX_NODE][MAX_NODE];
   int maxflow;

   int sum = 0;
   clear_graph(graph, MAX_NODE);
   // add the process to the target
   for (int i = 0; i < 10; i++) {
      graph[s][i+30] = 1;
   }
   
   while (getline(cin,str)) {
      if (str != "") {
	 
	 //cout << "in";
	 
	 char comp;
	 int pros;
	 char c;

	 istringstream ss(str);

	 ss >> comp >> pros;

	 //cout << " got " << pros << endl;
	 sum += pros;

	 graph[(int)(comp-'A')][t] = pros;
	 
	 while (ss >> c && c != ';') {
	    
	    graph[(int)(c-'0'+30)][(int)(comp-'A')] = pros;

	    // cout << "connecting process " << comp
	    // << " to comp " << (int)(c-'0'+30) << endl;
	 }
	 
      } else { // end of input
	 
	 maxflow = network_flow(graph, flow, MAX_NODE, s, t);
	 //cout << "flow = " << maxflow << endl;
	 //print_flow(flow, MAX_NODE);

	 if (sum > maxflow) {
	    cout << "!\n";
	 } else {

	    for (int i = 0; i < 10; i++) {
	       bool printed = false;
	       for (int j = 0; j < 26; j++) {
		  if (flow[i+30][j] == 1) {
		     cout << (char)(j+'A');
		     printed = true;
		  }
	       }
	       if (!printed) {
		  cout << "_";
	       }  
	    }
	    cout << endl;
	 }
	 
	 // clear network after printing
	 sum = 0;
	 clear_graph(graph, MAX_NODE);

	 // add the process to the target
	 for (int i = 0; i < 10; i++) {
	    graph[s][i+30] = 1;
	 }
      }
   }
    
   maxflow = network_flow(graph, flow, MAX_NODE, s, t);
   if (sum > maxflow) {
      cout << "!\n";
   } else {

      for (int i = 0; i < 10; i++) {
	 bool printed = false;
	 for (int j = 0; j < 26; j++) {
	    if (flow[i+30][j] == 1) {
	       cout << (char)(j+'A');
	       printed = true;
	    }
	 }
	 if (!printed) {
	    cout << "_";
	 }  
      }
      cout << endl;
   }
	 
   //cout << "flow = " << maxflow << endl;
   //print_flow(flow, MAX_NODE);
}
