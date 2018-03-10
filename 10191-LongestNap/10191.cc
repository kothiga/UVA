#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct TIME {
   int hh, mm, lh, lm; 
   bool operator<(const TIME& T) const {
      int T1 = (lh*60) + lm;
      int T2 = (T.lh*60) + T.lm;
      return T1 < T2;
   }
};

int main() {

   int n;
   int DAY = 1;

   const string S0 = "Day #";
   const string S1 = ": the longest nap starts at ";
   const string S2 = " and will last for ";
   const string S3 = " hours and ";
   const string S4 = " minutes.\n";
   
   while (cin >> n) {

      vector<TIME> v;

      TIME tmp;
      tmp.hh = 10;
      tmp.mm = 00;
      tmp.lh = 10;
      tmp.lm = 00;
      v.push_back(tmp);
      tmp.hh = 18;
      tmp.lh = 18;
      v.push_back(tmp);
     
      int h1, m1, h2, m2;
      char c;

      for (int i = 0; i < n; i++) {

	 cin >> h1 >> c >> m1
	     >> h2 >> c >> m2;
	 
	 string s;
	 getline(cin,s); // get the rest of the junk

	 tmp.lh = h1;
	 tmp.lm = m1;
	 tmp.hh = h2;
	 tmp.mm = m2;

	 v.push_back(tmp);
      }

      sort(v.begin(), v.end());

      int max = 0;
      int mh, mm;
      for (unsigned int i = 1; i < v.size(); i++) {

	 TIME s = v[i-1];
	 TIME e = v[i];

	 int start = (s.hh * 60) + s.mm;
	 int end = (e.lh * 60) + e.lm;
	 
	 // new longest nap time
	 if (end - start > max) {
	    max = (end - start);
	    mh = s.hh;
	    mm = s.mm;
	 }
      }

      cout << S0 << DAY++ << S1
	   << setfill('0') << setw(2) << mh << ":"
	   << setfill('0') << setw(2) << mm << S2;
      if (max >= 60) {
	 cout << (max / 60) << S3;
      }
      cout << (max % 60) << S4;
   }
}
