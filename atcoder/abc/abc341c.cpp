#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  const int M = 26;
  int N, Q; string S;
  cin >> N >> S >> Q;
  string T = "";
  rep(i, M) T += 'a' + i;
  rep(qi, Q) {
    char c, d; cin >> c >> d;
    rep(i, M) {
      if (T[i] == c) T[i] = d;
    }
  }
  
  string ans = "";
  rep(i, N) ans += T[S[i] - 'a'];
  cout << ans << endl;
}

