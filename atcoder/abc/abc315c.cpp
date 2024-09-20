#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define rall(a) (a).rbegin(), (a).rend()
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N; cin >> N;
  vector<int> F(N), S(N);
  rep(i, N) cin >> F[i] >> S[i];
  
  vector<P> C;
  rep(i, N) C.emplace_back(S[i], F[i]);
  sort(rall(C));
  int mf = C[0].second, ans = 0;
  for (int i = 1; i < N; i++) {
    int sum = C[0].first;
    if (C[i].second == mf) sum += C[i].first / 2;
    else sum += C[i].first;
    ans = max(ans, sum);
    if (C[i].second != mf) break;
  }
  
  cout << ans << endl;
}

