#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool solve() {
  const int N = 9;
  vector<vi> A(N, vi(N));
  rep(i, N) rep(j, N) cin >> A[i][j];
  
  // 行判定
  rep(i, N) {
    set<int> s;
    rep(j, N) s.insert(A[i][j]);
    if (s.size() != N) return false;
  }
  
  // 列判定
  rep(j, N) {
    set<int> s;
    rep(i, N) s.insert(A[i][j]);
    if (s.size() != N) return false;
  }
  
  // ブロック判定
  int M = N / 3;
  for (int si = 0; si < N; si += M) {
    for (int sj = 0; sj < N; sj += M) {
      set<int> s;
      for (int i = si; i < si + M; i++) {
        for (int j = sj; j < sj + M; j++) s.insert(A[i][j]);
      }
      if (s.size() != N) return false;
    }
  }
  
  return true;
}

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
}

