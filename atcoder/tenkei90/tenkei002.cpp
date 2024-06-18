#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool is_pattern_match(string str) {
  int tmp = 0;
  for (char c : str) {
    if (c == '(') tmp++;
    else tmp--;
    
    if (tmp < 0) return false;
  }
  if (tmp != 0) return false;
  
  return true;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < (1 << N); i++) {
    string str = "";
    for (int j = N - 1; j >= 0; j--) {
      if ((i & (1 << j)) != 0) str += ")";
      else str += "(";
    }
    
    if (is_pattern_match(str)) cout << str << endl;
  }
}
