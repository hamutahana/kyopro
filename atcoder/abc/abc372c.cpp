#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  // 引数で指定した要素番号を含む範囲に文字列"ABC"が存在するかを真偽値で返す
  auto check = [&](int x) -> bool {
    rep(k, 3) {
      int init = x - k;
      if (init < 0) continue;
      if (S.substr(init, 3) == "ABC") return true;
    }
    return false;
  };
  int ans = 0;
  rep(i, N) if (S.substr(i, 3) == "ABC") ans++;
  rep(qi, Q) {
    int x; char c; cin >> x >> c;
    x--;
    int cnt = 0;
    if (check(x)) cnt--;
    S[x] = c;
    if (check(x)) cnt++;
    ans += cnt;
    
    cout << ans << endl;
  }
}

