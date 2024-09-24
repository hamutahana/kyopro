#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

bool solve() {
  int N; cin >> N;
  vi A(N); rep(i, N) cin >> A[i];
  
  const int M = 2*N;
  vector<ll> S(M);
  S[0] = 0;
  for (int i = 1; i < M; i++) S[i] = S[i-1] + A[(i-1) % N];
  
  ll total = 0;
  rep(i, N) total += A[i];
  if (total % 10 != 0) return false;
  
  ll goal = total / 10;
  rep(i, N) {
    if (binary_search(S.begin(), S.end(), S[i] + goal)) return true;
  }
  return false;
}

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
}

