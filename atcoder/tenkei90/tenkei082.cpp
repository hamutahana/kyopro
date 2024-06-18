#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// a^b == res (mod MOD)を返す
int64_t modpow(int a, int b) {
  int64_t res = 1, p = a;
  for (int i = 0; i < 31; i++) {
    if ((b & (1 << i)) != 0) {
      res *= p;
      res %= MOD;
    }
    
    p *= p;
    p %= MOD;
  }
  
  return res;
}

int main() {
  int64_t L, R;
  cin >> L >> R;
  
  int64_t ans = 0, tmp = 1;
  for (int i = 1; i <= 19; i++) {
    int64_t count_mod;
    if (i == 19) {
      count_mod = R % MOD;
      ans += count_mod * i % MOD;
      ans %= MOD;
      break;
    }
    
    tmp *= 10;
    if (tmp < L) continue;
    if (tmp > R) {
      count_mod = ((R + L) % MOD) * ((R - L + 1) % MOD) % MOD * modpow(2, MOD - 2) % MOD;
      ans += count_mod * i % MOD;
      ans %= MOD;
      break;
    }
    
    count_mod = ((tmp + L - 1) % MOD) * ((tmp - L) % MOD) % MOD * modpow(2, MOD - 2) % MOD;
    ans += count_mod * i % MOD;
    ans %= MOD;
    L = tmp;
  }
  
  cout << ans << endl;
}
