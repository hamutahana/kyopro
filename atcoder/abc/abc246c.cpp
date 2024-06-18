#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, K, X;
  cin >> N >> K >> X;
  vi A(N); rep(i, N) cin >> A[i];
  
  int rest = K;
  rep(i, N) {
    int count = min(rest, A[i] / X);
    A[i] -= X * count; rest -= count;
  }
  
  if (rest != 0) {
    sort(A.rbegin(), A.rend());
    rep(i, N) {
      A[i] = 0; rest--;
      if (rest == 0) break;
    }
  }
  
  ll ans = 0;
  rep(i, N) ans += A[i];
  cout << ans << endl;
}

