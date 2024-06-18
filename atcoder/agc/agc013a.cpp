#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  vi A(N);
  rep(i, N) cin >> A.at(i);
  
  // type = 0 -> 増減未確定
  // type = 1 -> 単調非増加列
  // type = -1 -> 単調非減少列
  int ans = 1, type = 0;
  rep(i, N-1) {
    int diff = A.at(i+1) - A.at(i);
    if (type == 0) {
      if (diff > 0) type = 1;
      else if (diff < 0) type = -1;
    }
    
    if ((type == 1 && diff < 0) || (type == -1 && diff > 0)) {
      type = 0;
      ans++;
    }
  }
  cout << ans << endl;
}
