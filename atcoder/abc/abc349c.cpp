#include <bits/stdc++.h>
using namespace std;

bool solve() {
  string S, T; cin >> S >> T;
  int pos = 0;
  for (char c : S) {
    if (toupper(c) == T[pos]) pos++;
    if (pos == 2 && T[2] == 'X') return true;
    if (pos == 3) return true;
  }
  return false;
}

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
}

