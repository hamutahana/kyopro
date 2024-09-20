#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, M; cin >> N >> M;
  vi A(N); rep(i, N) cin >> A[i];
  
  sort(all(A));
  int ans = 0, j = 0;
  rep(i, N) {
    while (j < N && A[j] < A[i] + M) j++;
    ans = max(ans, j - i);
  }
  
  cout << ans << endl;
}

