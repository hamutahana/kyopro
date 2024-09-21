#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (n); i++)

bool solve() {
  string S; cin >> S;
  reverse(all(S));
  
  vector<string> T = { "dream", "dreamer", "erase", "eraser" };
  rep(i, T.size()) reverse(all(T[i]));
  int pos = 0;
  while (pos < S.size()) {
    bool ok = false;
    for (string t : T) {
      int c = t.size();
      if (S.substr(pos, c) == t) { pos += c; ok = true; }
    }
    if (!ok) return false;
  }
  return true;
}

int main() {
  if (solve()) cout << "YES" << endl;
  else cout << "NO" << endl;
}

