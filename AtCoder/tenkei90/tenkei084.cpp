#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  
  int64_t ans = 1LL * N * (N - 1) / 2;
  vector<int> L(0);
  char tmp = S.at(0);
  int count = 1;
  for (int i = 1; i < N; i++) {
    if (tmp == S.at(i)) count++;
    else {
      L.push_back(count);
      tmp = S.at(i);
      count = 1;
    }
  }
  L.push_back(count);
  
  for (int x : L) ans -= 1LL * x * (x - 1) / 2;
  
  cout << ans << endl;
}
