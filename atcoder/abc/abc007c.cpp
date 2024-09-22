#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vs = vector<string>;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const vi dy = { -1, 0, 1, 0 };
const vi dx = { 0, 1, 0, -1 };

int main() {
  int H, W; cin >> H >> W;
  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;
  sy--; sx--; gy--; gx--;
  vs s(H); rep(i, H) cin >> s[i];
  
  vector<vi> dist(H, vi(W, -1));
  queue<P> q;
  q.emplace(sy, sx); dist[sy][sx] = 0;
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    rep(k, 4) {
      int ny = y + dy[k], nx = x + dx[k];
      if (s[ny][nx] == '#') continue;
      if (dist[ny][nx] != -1) continue;
      q.emplace(ny, nx); dist[ny][nx] = dist[y][x] + 1;
    }
  }
  
  cout << dist[gy][gx] << endl;
}

