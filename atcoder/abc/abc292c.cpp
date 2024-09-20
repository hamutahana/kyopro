#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  vector<int> f(N);
  for (int i = 1; i <= N - 1; i++) {
    for (int j = 1; i * j <= N - 1; j++) {
      f[i*j]++;
    }
  }
  
  ll ans = 0;
  for (int i = 1; i <= N - 1; i++) {
    ans += f[i] * f[N-i];
  }
  cout << ans << endl;
}
