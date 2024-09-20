#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  
  vector<int> conti(N);
  conti[0] = 0;
  char pre = S[0];
  for (int i = 1; i < N; i++) {
    if (S[i] == pre) conti[i] = conti[i-1] + 1;
    else { pre = S[i]; conti[i] = conti[i-1]; }
  }
  
  rep(qi, Q) {
    int l, r; cin >> l >> r;
    l--; r--;
    int ans = conti[r] - conti[l];
    cout << ans << endl;
  }
}

