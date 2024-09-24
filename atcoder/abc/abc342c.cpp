// https://atcoder.jp/contests/abc342/tasks/abc342_c
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, Q; string S;
  cin >> N >> S >> Q;
  
  // 元々の文字が操作後にどの文字に置き換えられているかを保持する連想配列
  // mp[before_char] = after_char
  map<char, char> mp;
  rep(i, 26) mp['a' + i] = 'a' + i;
  rep(qi, Q) {
    char c, d; cin >> c >> d;
    for (auto &[_, after_char] : mp) if (after_char == c) after_char = d;
  }
  
  string ans = "";
  rep(i, S.size()) ans += mp[S[i]];
  cout << ans << endl;
}

