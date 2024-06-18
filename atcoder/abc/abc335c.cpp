#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
  
int main() {
  const vi dx = { 1, -1, 0, 0 };
  const vi dy = { 0, 0, 1, -1 };
  map<char, int> mp;
  mp['R'] = 0; mp['L'] = 1; mp['U'] = 2; mp['D'] = 3;
  
  int N, Q;
  cin >> N >> Q;
  deque<pii> ps;
  rep(i, N) ps.emplace_back(i + 1, 0);
  rep(i, Q) {
    int type; cin >> type;
    if (type == 1) {
      char c; cin >> c;
      auto [x, y] = ps.front();
      ps.emplace_front(x + dx.at(mp[c]), y + dy.at(mp[c]));
    } else {
      int p; cin >> p;
      auto [x, y] = ps.at(p-1);
      printf("%d %d\n", x, y);
    }
  }
}

