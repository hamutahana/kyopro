#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, Q; string S;
  cin >> N >> S >> Q;
  
  map<char, char> mp;
  rep(i, 26) mp['a' + i] = 'a' + i;
  rep(qi, Q) {
    char c, d; cin >> c >> d;
    // bf: before, af: after
    for (auto &[bf, af] : mp) if (af == c) af = d;
  }
  
  string ans = "";
  rep(i, S.size()) ans += mp[S[i]];
  cout << ans << endl;
}

