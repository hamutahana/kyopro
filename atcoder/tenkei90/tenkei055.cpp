#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, P, Q;
  cin >> N >> P >> Q;
  vector<int> A(N);
  rep(i, N) {
    int x;
    cin >> x;
    A.at(i) = x % P;
  }
  
  int ans = 0;
  rep(i, N) {
    for (int j = i+1; j < N; j++) {
      for (int k = j+1; k < N; k++) {
        for (int l = k+1; l < N; l++) {
          for (int m = l+1; m < N; m++) {
            int64_t r = 1;
            r *= A.at(i); r %= P;
            r *= A.at(j); r %= P;
            r *= A.at(k); r %= P;
            r *= A.at(l); r %= P;
            r *= A.at(m); r %= P;
            
            if (r == Q) ans++;
          }
        }
      }
    }
  }
  
  cout << ans << endl;
}
