#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 1; i <= (n); i++)

int main() {
  int D, G;
  cin >> D >> G;
  vi N(D+1), P(D+1);
  rep(i, D) cin >> N.at(i) >> P.at(i);

  int ans = 1001;
  for (int i = 0; i < (1 << D); i++) {
    int score = 0, count = 0, rest_num;
    for (int j = 1; j <= D; j++) {
      if ((i & (1 << (j - 1))) != 0) {
        score +=  (100 * j) * N.at(j) + P.at(j);
        count += N.at(j);
      } else {
        // コンプリートした問題の合計が目標スコアに達していない場合、未コンプリートの問題が一部解けた場合を考える
        // ループ終了後、コンプリートしていない問題番号の最大値が保持されている
        rest_num = j;
      }
    }

    if (score >= G) {
      ans = min(ans, count);
    } else {
      int rest_point = G - score;
      int rest_count = ceil(1.0 * rest_point / (100 * rest_num));
      if (rest_count < N.at(rest_num)) {
        count += rest_count;
        ans = min(ans, count);
      }
    }
  }
  cout << ans << endl;
}

