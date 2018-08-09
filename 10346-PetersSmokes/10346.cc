#include <iostream>

using namespace std;

typedef long long ll;

ll solve(ll n, ll k) {
   if (n < k) return 0;
   return (n/k) + solve((n/k)+(n%k), k);
}

int main() {
      
   ll n, k;
   while (cin >> n >> k) {
      cout << n + solve(n, k) << endl;
   }

   return 0;
}
