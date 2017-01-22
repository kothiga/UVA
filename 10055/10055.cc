/*
  Solution for UVA problem 10055
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=996

     Compile : g++11 -std=c++11 -o 10055 10055.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : get the abs value of 2 values >= 2^32
*/

#include <iostream>
#include <stdlib.h>
 
using namespace std;

int main() 
{
  // handles ints >= 2^32
  long long x, y;

  // while theres input
  while(cin >> x >> y)
    {
      // print the abs
      cout << abs(x-y) << '\n';
    }
}

 
