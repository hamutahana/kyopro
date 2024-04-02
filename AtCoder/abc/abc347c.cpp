#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int week = A + B;
  set<int> s;
  
  rep(i, N) {
    int x;
    cin >> x;
    s.insert(x % week);
  }
  
  vi D(all(s));
  sort(all(D));
  
  int d_size = D.size();
  if (d_size == 1) {
    cout << "Yes" << endl;
    return 0;
  }
  
  int min_range = D.at(d_size - 1) - D.at(0) + 1;
  rep(i, d_size - 1) {
    int range = (week - D.at(i+1)) + (D.at(i) + 1);
    min_range = min(min_range, range);
  }
  
  if (min_range <= A) cout << "Yes" << endl;
  else cout << "No" << endl;
}
