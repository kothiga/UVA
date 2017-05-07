/*
  Solution for UVA problem 10511
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1452

     Compile : g++11 -std=c++11 -o 10511 10511.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : Given a list of people who belong to a political
               party and a list of clubs, find a configuration
               of people representing different clubs so that no
               1 political party is represented more than half
*/


#include <iostream>
#include <map>
#include <algorithm>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Edge;
typedef list<Edge>::iterator EdgeIter;

struct Edge
{
   int to;
   int cap;
   int flow;
   bool is_real;
   EdgeIter partner;
   Edge(int t, int c, bool real = true)
      : to(t), cap(c), flow(0), is_real(real) {};

   int residual() const{ return cap - flow; }
};

struct Graph
{
   list<Edge> *nbr;
   int num_nodes;
   Graph(int n) : num_nodes(n){ nbr = new list<Edge>[num_nodes]; }
   ~Graph(){ delete[] nbr; }
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
   for (int i = 0; s != t; i++)
   {
      if (path[i]->is_real)
      {
	 path[i]->flow += flow;
	 path[i]->partner->cap += flow;
      }

      else
      {
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
   if (s == t) { return -1; }
   for (EdgeIter it = G.nbr[s].begin(); it != G.nbr[s].end(); ++it)
   {
      int v = it->to;
      if (it->residual() > 0 && !visited[v])
      {
	 path[step] = it; visited[v] = true;
	 int flow = augmenting_path(G, v, t, path, visited, step+1);
	 if (flow == -1){ return it->residual(); }
	 else if (flow > 0){ return min(flow, it->residual()); }
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

   do
   {
      fill(visited.begin(), visited.end(), false);
      if ((f = augmenting_path(G, s, t, path, visited)) > 0)
      { push_path(G, s, t, path, f); flow += f; }
   } while (f > 0);
  
   return flow;
}

const int MAX = 10000;

int main()
{
   // setup
   int DATASETS;
   cin >> DATASETS;
   cin.ignore();
   cin.ignore();

   while(DATASETS--)
   {
      Graph G(MAX);
      string s;

      // time stamps of different
      // things, to be used as nodes
      const int source = 0;
      const int target = 9999;
      
      int personTS = 0;
      int partyTS = 1001;
      int clubTS = 2005;

      double numClubs = 0;

      map<string, int> partyMap;
      map<string, int> clubMap;
      map<string, int> nameMap;
      map<int, string> council;

      vector<string> PartyList;      
      
      while(getline(cin, s))
      {
	 if(s == "") break;

	 personTS++;
	 
	 istringstream ss(s);
	 string name, party, club;
	 ss >> name >> party;

	 // add the name to the list
	 council[personTS] = name;
	 nameMap[name] = personTS;

	 // if this club has not been seen before, see it.
	 if(partyMap.find(party) == partyMap.end())
	 {
	    PartyList.push_back(party);
	    council[partyTS] = party;
	    partyMap[party] = partyTS++;
	 }

	 // add an edge from the party to the person
	 G.add_edge(partyMap[party], nameMap[name], 1);

	 while(ss >> club)
	 {
	    // if the club is not in the map add it
	    // and make an edge to the sink
	    if(clubMap.find(club) == clubMap.end())
	    {
	       numClubs++;
	       council[clubTS] = club;
	       clubMap[club] = clubTS++;
	       G.add_edge(clubMap[club], target, 1);
	    }

	    // create an edge from person to this club
	    G.add_edge(personTS, clubMap[club], 1);
	 }
      }

      // connect the parties to the source by the number of clubs
      for(unsigned int i = 0; i < PartyList.size(); i++)
	 G.add_edge(source, partyMap[PartyList[i]], (numClubs-1)/2);

      // output
      if(network_flow(G, source, target) == numClubs)
      {
	 for(auto &i : G.nbr[source])
	    if(i.flow)
	       for(auto &j : G.nbr[i.to])
		  if(j.flow)
		     for(auto &k : G.nbr[j.to])
			if(k.flow)
			   cout << council[j.to] << " "
				<< council[k.to] << endl;
      }
      
      else
	 cout << "Impossible.\n";
      if(DATASETS) cout << "\n";
   }
}
