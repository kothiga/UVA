/*
  Solution for UVA problem 10026
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=967

     Compile : g++11 -std=c++11 -o 10026 10026.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a list of jobs, where each job has a time of days
               that it takes to complete, and a penalty for each day that
               passes without the job completed, minimize the penalties
*/

#include <iostream>
#include <queue>

using namespace std;

// variable container
struct job
{
   int time;
   int pen;
   int enter;

   // overload for the priority queue
   bool operator<(const job& right) const
   {
      if((this->time * right.pen) == (right.time * this->pen))
	 return this->enter > right.enter;
      else
	 return (this->time * right.pen) > (right.time * this->pen);
   }
};

int main()
{
   // setup
   int DATASETS;
   cin >> DATASETS;
   while(DATASETS--)
   {
      priority_queue<job> ORDER;
      int n;
      cin >> n;
      for(int i = 1; i <= n; i++)
      {
	 int jobTime, jobPen;
	 cin >> jobTime >> jobPen;
	 job newJob;
	 newJob.time = jobTime;
	 newJob.pen = jobPen;
	 newJob.enter = i;

	 ORDER.push(newJob);
      }

      // output
      cout << (ORDER.top()).enter;
      ORDER.pop();
      while(!ORDER.empty())
      {
	 cout << " " << (ORDER.top()).enter;
	 ORDER.pop();      
      }
      cout << "\n";
      if(DATASETS)
	 cout << "\n";
   }
}

   

