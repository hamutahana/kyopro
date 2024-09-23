// https://atcoder.jp/contests/abc347/tasks/abc347_c
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool solve() {
  int N, A, B; cin >> N >> A >> B;
  int week = A + B;
  vector<int> D(N);
  rep(i, N) { cin >> D[i]; D[i] %= week; }
  
  sort(D.begin(), D.end());
  if (D[N - 1] - D[0] + 1 <= A) return true;
  rep(i, N-1) {
    int l = week - (D[i + 1] - D[i] - 1);
    if (l <= A) return true;
  }
  return false;
}

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
}

