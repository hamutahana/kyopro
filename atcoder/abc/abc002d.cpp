#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int N, M; cin >> N >> M;
  set<P> st;
  rep(i, M) {
    int a, b; cin >> a >> b;
    a--; b--;
    st.emplace(a, b);
    st.emplace(b, a);
  }
  
  int ans = 0;
  rep(i, (1 << N)) {
    vector<int> L;
    rep(j, N) if ((i >> j) & 1) L.push_back(j);
    int l = L.size();
    bool ok = true;
    rep(a, l) {
      for (int b = a + 1; b < l; b++) {
        if (!st.count(P(L[a], L[b]))) ok = false;
      }
    }
    if (ok) ans = max(ans, l);
  }
  
  cout << ans << endl;
}

