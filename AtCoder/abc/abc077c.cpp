#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  vi A(N), B(N), C(N);
  rep(i, N) cin >> A.at(i);
  rep(i, N) cin >> B.at(i);
  rep(i, N) cin >> C.at(i);
  
  sort(all(A));
  sort(all(B));
  sort(all(C));
  
  int64_t ans = 0;
  rep(i, N) {
    auto itA = lower_bound(all(A), B.at(i));
    auto itC = upper_bound(all(C), B.at(i));
    int64_t countA = distance(A.begin(), itA);
    int64_t countC = (int)C.size() - distance(C.begin(), itC);
    ans += countA * countC;
  }
  
  cout << ans << endl;
}
