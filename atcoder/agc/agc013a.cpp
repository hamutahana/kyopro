nclude <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N; cin >> N;
  vi A(N); rep(i, N) cin >> A[i];
  
  // type: { -1: 単調非減少, 0: 未確定, 1: 単調非増加 }
  int type = 0, cnt = 1;
  rep(i, N-1) {
    int diff = A[i + 1] - A[i];
    if (diff == 0) continue;
    else if (diff * type >= 0) type = diff / abs(diff);
    else { cnt++; type = 0; }
  }
  
  cout << cnt << endl;
}

