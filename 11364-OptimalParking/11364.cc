#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

   int n;
   cin >> n;

   while (n--) {

      int N;
      cin >> N;

      vector<int> v;      
      
      for (int x = 0; x < N; x++) {
	 int i;
	 cin >> i;
	 v.push_back(i);
      }

      sort(v.begin(), v.end());

      int total = (v[N-1] - v[0]) * 2;

      cout << total << endl;
   }
      

}
