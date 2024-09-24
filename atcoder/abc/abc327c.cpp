// https://atcoder.jp/contests/abc327/tasks/abc327_c
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool is_all_numbers(vi &a) {
  set<int> st;
  for (int x : a) st.insert(x);
  if (st.size() != 9) return false;
  return true;
}

bool solve() {
  vector<vi> a(9, vi(9));
  rep(i, 9) rep(j, 9) cin >> a[i][j];
  
  // 行判定
  rep(i, 9) if (!is_all_numbers(a[i])) return false;
  // 列判定
  rep(j, 9) {
    vi b;
    rep(i, 9) b.push_back(a[i][j]);
    if (!is_all_numbers(b)) return false;
  }
  // ブロック判定
  rep(p, 9) {
    int i = (p / 3) * 3, j = (p % 3) * 3;
    vi b;
    rep(q, 9) {
      int di = q / 3, dj = q % 3;
      b.push_back(a[i + di][j + dj]);
    }
    if (!is_all_numbers(b)) return false;
  }
  return true;
}

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
}

