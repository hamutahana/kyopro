#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  vi x(N), y(N), h(N);
  rep(i, N) cin >> x.at(i) >> y.at(i) >> h.at(i);
  
  for (int cx = 0; cx <= 100; cx++) {
    for (int cy = 0; cy <= 100; cy++) {
      bool is_ok = true;
      int ch;
      rep(i, N) {
        if (h.at(i) == 0) continue;
        
        ch = h.at(i) + abs(x.at(i) - cx) + abs(y.at(i) - cy);
        break;
      }
      
      rep(i, N) {
        int calc_h = ch - abs(x.at(i) - cx) - abs(y.at(i) - cy);
        calc_h = max(calc_h, 0);
        if (calc_h != h.at(i)) {
          is_ok = false;
          break;
        }
      }
      
      if (is_ok) {
        printf("%d %d %d\n", cx, cy, ch);
        return 0;
      }
    }
  }
}
