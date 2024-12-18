nclude <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using P = pair<int, int>;
using vs = vector<string>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const vi dx = { -1, 0, 1, 0 };
const vi dy = { 0, 1, 0, -1 };

int main() {
  int N, M; cin >> N >> M;
  vs S(N); rep(i, N) cin >> S[i];
  
  vector<vb> visited(N, vb(M));
  set<P> stopped;
  queue<P> q;
  visited[1][1] = true;
  q.emplace(1, 1); stopped.emplace(1, 1);
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    rep(k, 4) {
      int nx = x + dx[k], ny = y + dy[k];
      if (S[nx][ny] == '#') continue;
      while (S[nx][ny] == '.') { visited[nx][ny] = true; nx += dx[k]; ny += dy[k]; }
      nx -= dx[k]; ny -= dy[k];
      if (!stopped.count(P(nx, ny))) { q.emplace(nx, ny); stopped.emplace(nx, ny); }
    }
  }
  
  int ans = 0;
  rep(i, N) rep(j, M) {
    if (visited[i][j]) ans++;
  }
  cout << ans << endl;
}

