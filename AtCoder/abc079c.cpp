#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  // 定数を変えることで拡張性あり
  const int N = 4;
  const int M = 7;
  
  vi L(N);
  rep(i, N) {
    char c;
    cin >> c;
    int num = c - '0';
    L.at(i) = num;
  }
  
  for (int i = 0; i < (1 << (N - 1)); i++) {
    int init_val = L.at(0);
    int result = init_val;
    string ans = to_string(init_val);
    
    for (int j = 0; j < N - 1; j++) {
      int val = L.at(j + 1);
      if ((i & (1 << j)) != 0) {
        result += val;
        ans += "+" + to_string(val);
      } else {
        result -= val;
        ans += "-" + to_string(val);
      }
    }
    if (result == M) {
      ans += "=" + to_string(M);
      cout << ans << endl;
      return 0;
    }
  }
}
