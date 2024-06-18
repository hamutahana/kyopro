#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 1; i <= (n); i++)

const int64_t INF = 1001001001001001001;

int main() {
  const vi V = { -1, 1 };
  
  int n;
  cin >> n;
  vi a(n+1);
  rep(i, n) cin >> a.at(i);
  vector<int64_t> b(n+1);
  b.at(0) = 0;
  
  int64_t ans = INF;
  rep(t, 2) {
    int64_t count = 0;
    rep(i, n) {
      int val = V.at((i + t) % 2);
      b.at(i) = b.at(i-1) + a.at(i);
      // 符号が一致している場合
      if (b.at(i) * val > 0) continue;
      
      // 以下、符号が異なる場合
      count += abs(b.at(i) - val);
      b.at(i) = val;
    }
    
    ans = min(ans, count);
  }
  
  cout << ans << endl;
}
