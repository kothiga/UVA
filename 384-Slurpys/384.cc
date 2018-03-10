/*
  Solution for UVA problem 384
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=320

     Compile : g++11 -std=c++11 -o 384 384.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : Given a word, follow a very specific set of rules
               to determine of a single word is a 'slurpy'
*/


#include <iostream>
#include <string>

using namespace std;

int slump(string s, int start, int end)
{
   // is slump if First char is D or E
   // and second char is F
   // also if the pos after start is end, it cant be
   if( (s[start] == 'D' || s[start] == 'E') && start+1 != end )
   {
      if(s[start+1] != 'F') return 0;
   
      // find first pos that is not F
      int i;
      for( i = start+2; i < end; i++)
	 if(s[i] != 'F') break;

      if( s[i] == 'G' ) return i+1;
			
      int visit = slump(s, i, end);
      if( visit ) { return visit; }
   }
   
   return 0;
}


int slimp(string s, int start, int end)
{
   if( s[start] != 'A' || start+1 == end ) return 0;
   if( s[start+1] == 'H' ) return 2+start;

   //case 1
   if( s[start+1] == 'B' )
   {
      int visit = slimp(s, start+2, end);
      if( visit && s[visit] == 'C' ) return visit+1;	 
   }

   // case 2
   int visit = slump(s, start+1, end);
   if( visit && visit != end && s[visit] == 'C' )
      return visit+1;
   
   return 0;
}

bool slurpy(string s)
{
   int end = s.length();
   int visit = slimp(s, 0, end);
   if(visit)
   {
      int slumpv = slump(s, visit, end);
      if( slumpv && slumpv == end) return true;      
   }
   return false;
}

int main()
{
   // setup
   int DATASETS;
   cin >> DATASETS;
   cout << "SLURPYS OUTPUT\n";
   while(DATASETS--)
   {
      string s;
      cin >> s;

      // output
      if( slurpy(s) )
	 cout << "YES\n";
      else
	 cout << "NO\n";
   }
   cout << "END OF OUTPUT\n";
}
