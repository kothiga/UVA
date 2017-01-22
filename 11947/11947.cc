/*
  Solution for UVA problem 11947
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3098

     Compile : g++11 -std=c++11 -o 11947 11947.cc -Wall
  Written by : Austin Kothig
    Semester : SPRING 2017
     Problem : given a date, produce expectency date (40 weeks later)
               as well as astronomy sign
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string astrology[13]{
   "capricorn"  ,
   "aquarius"   ,
   "pisces"     , 
   "aries"      , 
   "taurus"     , 
   "gemini"     , 
   "cancer"     ,
   "leo"        ,
   "virgo"      ,
   "libra"      ,
   "scorpio"    ,
   "sagittarius",
   "capricorn" };

//                          J   F   M   A   M   J   J   A   S   O   N   D
const int dayRange[13]{ 0, 21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23 };

string solve(int&, int&, int&);
int dayInMonth(int, int);
bool leap(int);

int main()
{     
  // set up
  int n, count = 0;
  cin >> n;
  while(n--)
    {
      // get the whole string 
      string inString, sign = "0";
      cin >> inString;

      // break it down
      int day, month, year;
      month = stoi(inString.substr(0, 2));
      day = stoi(inString.substr(2, 2));
      year = stoi(inString.substr(4));

      // find date and sign
      sign = solve(month, day, year);
      
      // output
      count++;
      cout << count << " "
	   << setw(2) << setfill('0') << month << "/"
	   << setw(2) << setfill('0') << day << "/"
	   << setw(4) << setfill('0') << year << " "
	   << sign << "\n";
      
    }
}

string solve(int& month, int& day, int& year)
{
  // do work for each week in the cycle
  for(int i = 0; i < 40; ++i)
    {
      // get the number of days for the current month
      int currMonth = dayInMonth(month, year);

      // add a week
      day = (day + 6) % currMonth + 1;
      
      // the next month has occured
      if(day < 8)
	{
	  // add a month
	  month = month % 12 + 1;

	  // next year has occured
	  if (month == 1)
	    year++;
	}
    }
  
  // return the correct sign
  if(day < dayRange[month])
    return astrology[month-1];
  return astrology[month];
}

int dayInMonth(int month, int year)
{
  // self-explanatory 
  if(month == 4 || month == 6 || month == 9 || month == 11)
    return 30;

  if(month == 2 && leap(year))
    return 29;

  if(month == 2 && !(leap(year)))
    return 28;

  return 31;	  
}

bool leap(int year)
{
  // years divisible by 4 and not divisible by 100 but is
  // divisible by 400 are leap years according to google
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}


