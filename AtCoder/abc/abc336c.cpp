#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  const int M = 5;
  ll N; cin >> N;
  
  N--;
  
  ll ans = 0, dig = 1;
  do {
    int num = (N % M) * 2;
    ans += num * dig;
    N /= M; dig *= 10;
  } while (N != 0);
  
  cout << ans << endl;
}

