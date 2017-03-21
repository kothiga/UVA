/*
  Solution for UVA problem 674
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=615

     Compile : g++11 -std=c++11 -o 674 674.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : count the number of different ways
               to produce a sum of coins. 
*/

#include <iostream>

using namespace std;

int const cents[5] = { 50, 25, 10, 5, 1, };
long long coins[7490][5];

long long countCoins(int money, int k)
{
   // sum cannot be created
   if(money < 0) return 0;

   // a sum has been made
   if(money == 0) return 1;

   // this has been computed with this many conis before, return
   if(coins[money][k] != 0) return coins[money][k];

   // count the number of ways
   long long total = 0;
   for(int i = k; i < 5; i++)
   {
      total += countCoins(money-cents[i], i);
   }
   return coins[money][k] = total;   
}

int main()
{
   // setup
   int money;

   // output
   while(cin >> money)
      cout << countCoins(money, 0) << "\n";
}

