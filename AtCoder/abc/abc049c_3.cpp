#include <bits/stdc++.h>
using namespace std;
using vs = vector<string>;
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  vs W = { "dream", "dreamer", "erase", "eraser" };
  
  string S;
  cin >> S;
  
  reverse(all(S));
  rep(i, W.size()) reverse(all(W.at(i)));
  
  int i = 0;
  while (i < S.size()) {
    bool is_match = false;
    for (string w : W) {
      int w_length = w.size();
      if (i + w_length > S.size()) continue;
      if (S.substr(i, w_length) != w) continue;
      i += w_length;
      is_match = true;
    }
    
    if (!is_match) {
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
}
