#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N; cin >> N;
  
  vector<int> st;
  rep(i, N) {
    int a; cin >> a;
    st.push_back(a);
    while (st.size() > 1) {
      int x = st.back(), y = st.end()[-2];
      if (x != y) break;
      
      rep(k, 2) st.pop_back();
      st.push_back(x+1);
    }
  }
  
  cout << st.size() << endl;
}
