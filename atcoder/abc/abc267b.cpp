#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
#define rep(i, n) for (int i = 1; i <= (n); i++)

const int COL_COUNT = 7;
string S;
// 配列のインデックスを列番号を合わせるために、0番目に空配列を入れている
vii L = {{}, {7}, {4}, {2, 8}, {1, 5}, {3, 9}, {6}, {10}};

// 引数の列において、ピンが全て倒れているかを判定
bool is_empty_col(int col) {
  for (int x : L.at(col)) {
    if (S.at(x) == '1') return false;
  }
  return true;
}

int main() {
  cin >> S;
  // 文字列のインデックスをピン番号を合わせるために、先頭に文字xを入れている
  S = "x" + S;
  
  // ピン1が倒れている場合
  if (S.at(1) != '0') {
    cout << "No" << endl;
    return 0;
  }
  
  for (int i = 1; i <= COL_COUNT; i++) {
    if (is_empty_col(i)) continue;
      
    for (int j = i + 1; j <= COL_COUNT; j++) {
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
