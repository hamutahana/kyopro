#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
  ll L, R; cin >> L >> R;
  
  vector<P> ans;
  while (L < R) {
    ll tmp = 1;
    while (L % tmp == 0 && L + tmp <= R) tmp *= 2;
    tmp /= 2;
    ans.emplace_back(L, L + tmp);
    L += tmp;
  }
  
  cout << ans.size() << endl;
  for (auto [l, r] : ans) cout << l << ' ' << r << endl;
}

