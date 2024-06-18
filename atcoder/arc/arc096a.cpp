#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int ans;
  
  if (A + B <= 2*C) {
    ans = A * X + B * Y;
    cout << ans << endl;
    return 0;
  }
  
  map<int, int> m;
  m[X] = A;
  m[Y] = B;
  ans += 2*C * min(X, Y);
  
  int rest_price = min(m[max(X, Y)], 2*C);
  int rest_count = abs(X - Y);
  ans += rest_price * rest_count;
  cout << ans << endl;
}
