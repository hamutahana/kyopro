#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
  int N, M;
  cin >> N >> M;
  vii G(N+1, vi(0));
  for (int i = 1; i <= M; i++) {
    int x, y;
    cin >> x >> y;
    G.at(x).push_back(y);
    G.at(y).push_back(x);
  }
  
  int max_count = 0;
  for (int i = 0; i < (1 << N); i++) {
    bool is_ok = true;
    vi L(0);
    for (int j = 0; j < N; j++) {
      if ((i & (1 << j)) != 0) L.push_back(j + 1);
    }
    
    for (int x : L) {
      set<int> s;
      for (int y : G.at(x)) s.insert(y);
      
      for (int y : L) {
        if (y == x) continue;
        if (!s.count(y)) {
          is_ok = false;
          break;
        }
      }
      
      if (!is_ok) break;
    }
    
    if (is_ok) {
      int count = L.size();
      max_count = max(max_count, count);
    }
  }
  cout << max_count << endl;
}
