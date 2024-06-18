#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (n); i++)

map<char, int> mp = { {'R', 0}, {'L', 1}, {'U', 2}, {'D', 3} };
vector<int> dx = { 1, -1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };

int main() {
  int N, Q; cin >> N >> Q;
  
  vector<P> pos;
  rep(i, N) pos.emplace_back(i+1, 0);
  reverse(all(pos));
  
  rep(qi, Q) {
    int type; cin >> type;
    if (type == 1) {
      char c; cin >> c;
      auto [x, y] = pos.back();
      pos.emplace_back(x + dx[mp[c]], y + dy[mp[c]]);
    }
    if (type == 2) {
      int p; cin >> p;
      auto [x, y] = pos[pos.size() - p];
      printf("%d %d\n", x, y);
    }
  }
}

