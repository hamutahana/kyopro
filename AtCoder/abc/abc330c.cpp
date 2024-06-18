#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) (a).begin(), (a).end()

const int INF = 1001001001;
void chmin(ll &a, ll b) { if (a > b) a = b; }

int main() {
  ll D; cin >> D;
  ll M = 1000010;
  vector<ll> power(M+1);
  for (ll i = 0; i <= M; i++) power[i] = i * i;
  
  ll ans = INF;
  for (ll x = 0; x * x <= D; x++) {
    ll rest = D - x * x;
    auto it = lower_bound(all(power), rest);
    ll j = distance(power.begin(), it);
    ll v1 = abs(rest - power[j]), v2 = abs(rest - power[j-1]);
    chmin(ans, v1); chmin(ans, v2);
  }
  
  cout << ans << endl;
}

