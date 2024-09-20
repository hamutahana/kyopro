#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N; cin >> N;
  vector<int> A(N), B(N), C(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N) cin >> C[i];
  
  sort(all(A));
  sort(all(C));
  
  ll ans = 0;
  rep(i, N) {
    auto itA = lower_bound(all(A), B[i]);
    auto itC = upper_bound(all(C), B[i]);
    int a = distance(A.begin(), itA);
    int c = N - distance(C.begin(), itC);
    ans += (ll)a * c;
  }
  
  cout << ans << endl;
}

