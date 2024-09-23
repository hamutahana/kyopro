// https://atcoder.jp/contests/abc267/tasks/abc267_b
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

// 列ごとに存在するピン番号の配列を持つ二重配列
vector<vi> L = {{7}, {4}, {2, 8}, {1, 5}, {3, 9}, {6}, {10}};

bool solve() {
  string S; cin >> S;
  
  // ピン1が倒れていない場合
  if (S[0] == '1') return false;
  
  auto existed_pin = [&](vi &a) {
    for (int x : a) if (S[x-1] == '1') return true;
    return false;
  };
  // ピンが残っている列（以下、残列と呼ぶ）の番号を格納する配列
  vi existed_cols;
  rep(i, L.size()) {
    if (existed_pin(L[i])) existed_cols.push_back(i);
  }
  // 残列が2つ未満の場合
  if (existed_cols.size() < 2) return false;
  
  rep(i, existed_cols.size() - 1) {
    // 残列の間にピンが全て倒れている列が存在する場合
    if (existed_cols[i+1] - existed_cols[i] > 1) return true;
  }
  return false;
}

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
}
