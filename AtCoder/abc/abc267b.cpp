#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;

const int col_count = 7;
string S;
// 実装時は、実際のピン番号から1を引いた値を用いる
vii L = {{6}, {3}, {1, 7}, {0, 4}, {2, 8}, {5}, {9}};

// 引数の列において、ピンが全て倒れているかを判定
bool is_empty_col(int col) {
  bool is_empty_col = true;
  for (int x : L.at(col)) {
    if (S.at(x) == '1') is_empty_col = false;
  }
  return is_empty_col;
}

int main() {
  cin >> S;
  
  // ピン1が倒れている場合
  if (S.at(0) != '0') {
    cout << "No" << endl;
    return 0;
  }
  
  for (int i = 0; i < col_count; i++) {
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
