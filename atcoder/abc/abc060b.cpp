#include <bits/stdc++.h>
using namespace std;
using vb = vector<bool>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  vb L(B, false);
  int r = A % B, tmp = 0;
  // A * 1, A * 2, ・・・, A * (B - 1)で余りのパターンは網羅している
  rep(i, B) {
    tmp += r;
    tmp %= B;
    L.at(tmp) = true;
  }
  
  if (L.at(C)) cout << "YES" << endl;
  else cout << "NO" << endl;
}
