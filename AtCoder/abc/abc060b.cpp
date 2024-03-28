#include <bits/stdc++.h>
using namespace std;
using vb = vector<bool>;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int64_t INF = 1001001001001001001;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  vb L(B, false);
  int r = A % B, tmp = 0;
  rep(i, B) {
    tmp = (tmp + r) % B;
    L.at(tmp) = true;
  }
  
  string ans = L.at(C) ? "YES" : "NO";
  cout << ans << endl;
}
