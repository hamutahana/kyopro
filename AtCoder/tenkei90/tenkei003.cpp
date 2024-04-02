#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
#define rep(i, n) for (int i = 1; i <= (n); i++)

int main() {
  int N;
  cin >> N;
  vii G(N+1, vi(0));
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  
  queue<int> q;
  int max_dist = -1, idx = 1;
  rep(i, 2) {
    vi dist(N+1, -1);
    q.push(idx);
    dist.at(idx) = 0;
    while (!q.empty()) {
      int pos = q.front();
      q.pop();
      for (int next : G.at(pos)) {
        if (dist.at(next) == -1) {
          dist.at(next) = dist.at(pos) + 1;
          q.push(next);
        }
      }
    }
    
    rep(i, N) {
      if (dist.at(i) > max_dist) {
        max_dist = dist.at(i);
        idx = i;
      }
    }
  }
  
  int ans = max_dist + 1;
  cout << ans << endl;
}
