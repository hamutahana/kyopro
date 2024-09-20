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
    G[a].emplace_back(b, c);
    G[b].emplace_back(a, c);
  }
  
  vector<bool> used(N+1);
  int ans = 0;
  auto dfs = [&](auto dfs, int v, int dist) -> void {
    used[v] = true;
    ans = max(ans, dist);
    for (auto [nv, ndist] : G[v]) {
      if (used[nv]) continue;
      dfs(dfs, nv, dist + ndist);
    }
    used[v] = false;
  };
  
  rep(i, N) dfs(dfs, i, 0);
  cout << ans << endl;
}

