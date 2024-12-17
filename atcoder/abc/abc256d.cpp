nclude <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int INF = 1001001001;
void chmax(int &a, int b) { a = max(a, b); }

int main() {
  int N; cin >> N;
  vector<P> L(N);
  rep(i, N) cin >> L[i].first >> L[i].second;
  
  sort(L.begin(), L.end());
  vector<P> ans;
  ans.push_back(L[0]);
  for (int i = 1; i < N; i++) {
    if (L[i].first > ans.back().second) ans.push_back(L[i]);
    else chmax(ans.back().second, L[i].second);
  }
  
  for (auto [l, r] : ans) printf("%d %d\n", l, r);
}

