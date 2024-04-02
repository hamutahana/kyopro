#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> L(N+1, 0);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    
    if (x > y) L.at(x)++;
    else if (x < y) L.at(y)++;
  }
  
  int ans = 0;
  rep(i, N) {
    if (L.at(i) == 1) ans++;
  }
  
  cout << ans << endl;
}

