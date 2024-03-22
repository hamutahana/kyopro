#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  const int M = 46;
  int N;
  cin >> N;
  vii L(3, vi(M, 0));
  rep(i, 3) {
    rep(j, N) {
      int r;
      cin >> r;
      r %= M;
      L.at(i).at(r)++;
    }
  }
  
  int64_t ans = 0;
  rep(i, M) {
    rep(j, M) {
      rep(k, M) {
        int r = (i + j + k) % M;
        if (r != 0) continue;
        
        ans += 1LL * L.at(0).at(i) * L.at(1).at(j) * L.at(2).at(k);
      }
    }
  }
  cout << ans << endl;
}
