/*
  Solution for UVA problem 10047
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=988

     Compile : g++11 -std=c++11 -o 10047 10047.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a grid with obsticales, find the minimum
               amount of unit time to traverse from a start
               square to a target square, with your wheel being "green"
*/


#include <iostream>
#include <queue>
#include <string.h>
#include <utility>

using namespace std;

const int MAX_MN = 28;
const int MAX_DIR = 4;
const int MAX_CLR = 5;
const int X[4] {-1, 0, 1, 0};
const int Y[4] { 0, 1, 0,-1};
char grid[MAX_MN][MAX_MN];
bool visited[MAX_MN][MAX_MN][MAX_DIR][MAX_CLR];

struct Node
{
   int x, y, clr, dir, time;
   Node(int i, int j)
   { x = i; y = j; clr = 0; dir = 0; time = 0; }

   Node(int state, Node cur)
   {
      // set the things they share
      clr = cur.clr;
      time = cur.time+1;
      x = cur.x;
      y = cur.y;

      // do different things
      switch(state)
      {
	 // forward
	 case 0:
	    dir = cur.dir;
	    clr = (cur.clr + 1) % MAX_CLR;
	    x += X[dir];
	    y += Y[dir];  
	    break;
	    
	 // right
	 case 1:
	    dir = (cur.dir + 1) % MAX_DIR;
	    break;
	    
	 // left
	 case 2:
	    dir = (MAX_DIR + cur.dir - 1) % MAX_DIR;
	    break;
      }
   }

   // used for asking have I been here before
   bool previsit(){ return visited[x][y][dir][clr]; }

   // used for saying I have been here before
   void visit(){ visited[x][y][dir][clr] = true; }
};

void make_board(int m, int n)
{
   // fill everything as false
   memset(visited, false, sizeof visited);  

   // surround the board with
   // unreachable buffer squares
   for(int i = 0; i <= m; i++)
      for(int j = 0; j <= n; j++)
	 if(i == 0 || j == 0 || i == m || j == n)
	    grid[i][j] = '#';
	
}

int main()
{
   // setup
   int m, n;
   int CASE = 0;
   while(cin >> m >> n && (m != 0 && n != 0))
   {
      // formatting
      if(CASE) cout << "\n";
      
      // increase these by one for buffer edges
      m++; n++;
      make_board(m, n);
      pair<int, int> START, END;
      for(int i = 1; i < m; i++)
	 for(int j = 1; j < n; j++)
	 {
	    cin >> grid[i][j];
	    if(grid[i][j] == 'S') START = make_pair(i, j);
	    else if(grid[i][j] == 'T') END = make_pair(i, j);
	 }

      // bfs
      Node start(START.first, START.second);
      int finish = 0;

      queue<Node> q;
      q.push(start);

      while(!q.empty())
      {
	 // grab current
	 Node cur = q.front(); q.pop();

	 // if we are at the end . . . leave.
	 if(cur.x == END.first && cur.y == END.second && cur.clr == 0)
	 {
	    finish = cur.time;
	    break;
	 }

	 // only do something if we are not standing on a #
	 // and we have not been to this spot before
	 if(grid[cur.x][cur.y] != '#' && !(cur.previsit()))
	 {
	    // do not come back here
	    cur.visit();
	    
	    // make the next three states
	    Node forward(0, cur),
	           right(1, cur),
	            left(2, cur);

	    // add them to the bfs
	    q.push(forward); q.push(right); q.push(left);
	 }
      }

      // output
      CASE++;
      cout << "Case #" << CASE << "\n";
      if(finish)
	 cout << "minimum time = " << finish << " sec\n";
      else
	 // if finish was never found this
	 // will occur since finish == 0
	 cout << "destination not reachable\n";    
   }
}
