#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  regex re("(dream|dreamer|erase|eraser)*");
  if (regex_match(S, re)) cout << "YES" << endl;
  else cout << "NO" << endl;
}
