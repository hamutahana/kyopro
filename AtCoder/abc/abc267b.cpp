#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int col_count = 7;
string S;
// 実装時は、ピン番号を実際の番号から1引いた値として考える
vii L = {{6}, {3}, {1, 7}, {0, 4}, {2, 8}, {5}, {9}};

bool is_empty_col(int col) {
  bool is_empty_col = true;
  for (int x : L.at(col)) {
    if (S.at(x) == '1') is_empty_col = false;
  }
  return is_empty_col;
}

int main() {
  cin >> S;
  
  // ピン0が倒れている場合
  if (S.at(0) != '0') {
    cout << "No" << endl;
    return 0;
  }
  
  
  rep(i, col_count) {
    // 列i(0~6)のピンが全て倒れている場合
    if (is_empty_col(i)) continue;
      
    for (int j = i + 1; j < col_count; j++) {
      if (is_empty_col(j)) continue;
      
      for (int k = i + 1; k < j; k++) {
        if (is_empty_col(k)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
