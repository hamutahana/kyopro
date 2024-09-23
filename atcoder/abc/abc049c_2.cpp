// https://atcoder.jp/contests/abc049/tasks/arc065_a
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  regex re("(dream|dreamer|erase|eraser)*");
  if (regex_match(S, re)) cout << "YES" << endl;
  else cout << "NO" << endl;
}
