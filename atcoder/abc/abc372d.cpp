nclude <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int N; cin >> N;
  vi H(N); rep(i, N) cin >> H[i];
  
  vi L, ans;
  ans.push_back(0);
  for (int i = N - 2; i >= 0; i--) {
    while (L.size() > 0 && L.back() < H[i+1]) L.pop_back();
    L.push_back(H[i+1]);
    ans.push_back(L.size());
  }
  reverse(ans.begin(), ans.end());
  
  for (int x : ans) cout << x << " ";
  cout << endl;
}

