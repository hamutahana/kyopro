// https://atcoder.jp/contests/abc104/tasks/abc104_c
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int INF = 1001001001;

int main() {
  int D, G; cin >> D >> G;
  vi N(D), P(D), S(D);
  rep(i, D) cin >> N[i] >> P[i];
  rep(i, D) S[i] = 100 * (i + 1) * N[i] + P[i];
  
  int ans = INF;
  // コンプリートした問題で全探索
  rep(i, (1 << D)) {
    vi comp;
    int uncomp;
    rep(j, D) {
      if ((i >> j) & 1) comp.push_back(j);
      else uncomp = j;
    }
    int score = 0, cnt = 0;
    for (int j : comp) { score += S[j]; cnt += N[j]; }
    if (score >= G) ans = min(ans, cnt);
    else {
      int rest_score = G - score, point = 100 * (uncomp + 1);
      if (rest_score <= point * (N[uncomp] - 1)) {
        cnt += (rest_score + point - 1) / point;
        ans = min(ans, cnt);
      }
    }
  }
  
  cout << ans << endl;
}

