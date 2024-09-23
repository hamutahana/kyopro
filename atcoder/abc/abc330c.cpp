// https://atcoder.jp/contests/abc330/tasks/abc330_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1001001001;
void chmin(ll &a, ll b) { if (a > b) a = b; }

int main() {
  ll D; cin >> D;
  
  // y*y >= D を満たす値を初期値に設定
  ll y = 2e6, ans = D;
  for (ll x = 0; x * x <= D; x++) {
    while (y > 0 && x*x + y*y >= D) y--;
    ll v1 = abs(x*x + y*y - D);
    ll v2 = abs(x*x + (y+1)*(y+1) - D);
    chmin(ans, v1); chmin(ans, v2);
  }
  
  cout << ans << endl;
}

