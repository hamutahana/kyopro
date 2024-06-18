#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 1; i <= (n); i++)

const int INF = 1001001001;

int main() {
  int D, G;
  cin >> D >> G;
  vi N(D+1), P(D+1);
  rep(i, D) cin >> N.at(i) >> P.at(i);

  int ans = INF;
  // コンプリートした問題の組をビット全探索
  for (int i = 0; i < (1 << D); i++) {
    int score = 0, count = 0, rest_max_dif;
    for (int j = 1; j <= D; j++) {
      if ((i & (1 << (j - 1))) != 0) {
        score +=  (100 * j) * N.at(j) + P.at(j);
        count += N.at(j);
      } else {
        // コンプリートした問題の合計スコアが目標に達していない場合、次に、未コンプリートの問題が一部解けた場合を考える
        // ループ終了後、非コンプリート問題の中で最大の難易度が保持されている
        rest_max_dif = j;
      }
    }

    if (score >= G) ans = min(ans, count);
    else {
      int rest_point = G - score;
      int rest_count = ceil(1.0 * rest_point / (100 * rest_max_dif));
      if (rest_count < N.at(rest_max_dif)) {
        count += rest_count;
        ans = min(ans, count);
      }
    }
  }
  
  cout << ans << endl;
}

