#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int64_t INF = 1001001001001001001;

int main() {
  const vi V = { -1, 1 };
  
  int n;
  cin >> n;
  vector<int64_t> a(n), b(n);
  rep(i, n) cin >> a.at(i);
  
  int64_t ans = INF;
  rep(t, 2) {
    int64_t count = 0;
    rep(i, n) {
      int val = V.at((i + t) % 2);
      if (i == 0) b.at(i) = a.at(i);
      else b.at(i) = b.at(i-1) + a.at(i);
      
      if (val * b.at(i) > 0) continue;
      count += 1LL * abs(b.at(i) - val);
      b.at(i) = val;
    }
    
    ans = min(ans, count);
  }
  
  cout << ans << endl;
}
