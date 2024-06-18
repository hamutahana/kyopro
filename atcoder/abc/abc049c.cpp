#include <bits/stdc++.h>
using namespace std;
using vs = vector<string>;

int main() {
  const vs W = { "dream", "dreamer", "erase", "eraser" };
  
  string S;
  cin >> S;
  
  while (S != "") {
    bool is_ok = false;
    for (string w : W) {
      int i = (int)S.size() - (int)w.size();
      if (i < 0) continue;
      if (S.substr(i) != w) continue;
      
      S.erase(i);
      is_ok = true;
    }
    
    if (!is_ok) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
