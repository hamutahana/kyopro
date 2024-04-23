#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int M = 26;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vc L(M);
  rep(i, M) {
    char c = 'a' + i;
    L.at(i) = c;
  }
  int Q;
  cin >> Q;
  rep(i, Q) {
    char x, y;
    cin >> x >> y;
    rep(i, M) {
      if (L.at(i) == x) L.at(i) = y;
    }
  }
  
  vb is_changed(N, false);
  rep(i, M) {
    int bf_char = 'a' + i, af_char = L.at(i);
    rep(i, N) {
      if (S.at(i) == bf_char && !is_changed.at(i)) {
        S.at(i) = af_char;
        is_changed.at(i) = true;
      }
    }
  }
  
  cout << S << endl;
}

