#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N; cin >> N;
  
  vector<int> st;
  rep(i, N) {
    int a; cin >> a;
    while (!st.empty()) {
      if (st.back() != a) break;
      
      st.pop_back();
      a++;
    }
    st.push_back(a);
  }
  
  cout << st.size() << endl;
}
