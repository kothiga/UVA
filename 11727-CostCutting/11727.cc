#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

   vector<int> v;
   v.push_back(0);
   v.push_back(0);
   v.push_back(0);

   int n;
   cin >> n;

   for (int i = 0; i < n; i++) {

      cin >> v[0] >> v[1] >> v[2];
      sort(v.begin(), v.end());


      cout << "Case " << i+1 << ": " << v[1] << endl;
   }
   
}
