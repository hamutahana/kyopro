// https://atcoder.jp/contests/abc317/tasks/abc317_c
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, M; cin >> N >> M;
  vector<vector<P>> G(N);
  rep(i, M) {
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    G[a].emplace_back(c, b);
    G[b].emplace_back(c, a);
  }
  
  int ans = 0;
  vector<bool> visited(N, false);
  auto f = [&](auto f, int v, int d) -> void {
    visited[v] = true;
    ans = max(ans, d);
    for (auto [cost, nv] : G[v]) {
      if (visited[nv]) continue;
      f(f, nv, d + cost);
    }
    visited[v] = false;
  };
  rep(i, N) f(f, i, 0);
  
  cout << ans << endl;
}

