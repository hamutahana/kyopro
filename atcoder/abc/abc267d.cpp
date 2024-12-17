nclude <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep1(i, n) for (int i = 1; i <= (n); ++i)

const ll INF = 1e18;
void chmax(ll &a, ll b) { a = max(a, b); }

int main() {
  int N, M; cin >> N >> M;
  vi A(N + 1); rep1(i, N) cin >> A[i];
  
  vector<ll> dp(M + 1, -INF);
  dp[0] = 0;
  rep1(i, N) {
    for (int j = min(i, M); j > 0; j--) {
      if (dp[j - 1] == -INF) continue;
      chmax(dp[j], dp[j - 1] + j * A[i]);
    }
  }
  
  cout << dp[M] << endl;
}

