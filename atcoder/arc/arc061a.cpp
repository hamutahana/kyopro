#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int64_t ans = 0;
  int gap_count = S.size() - 1;
  for (int i = 0; i < (1 << gap_count); i++) {
    string tmp = string(1, S.at(0));
    for (int j = 0; j < gap_count; j++) {
      if ((i & (1 << j)) != 0) {
        ans += stoll(tmp);
        tmp = "";
      }
      tmp += S.at(j+1);
    }
    ans += stoll(tmp);
  }
  
  cout << ans << endl;
}
