#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (n); i++)

const int INF = 1001001001;

int main() {
  int N;
  cin >> N;
  vi A(N);
  rep(i, N) cin >> A.at(i);
  int Q;
  cin >> Q;
  vi B(Q);
  rep(i, Q) cin >> B.at(i);
  
  sort(all(A));
  
  rep(i, Q) {
    auto it = lower_bound(all(A), B.at(i));
    int j = distance(A.begin(), it);
    int diff = INF;
    if (j <= N - 1) {
      int diff1 = abs(A.at(j) - B.at(i));
      diff = min(diff, diff1);
    }
    if (j >= 1) {
      int diff2 = abs(A.at(j - 1) - B.at(i));
      diff = min(diff, diff2);
    }
    
    cout << diff << endl;
  }
}
