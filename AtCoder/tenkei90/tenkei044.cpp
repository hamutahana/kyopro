#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (n); i++)

int main() {
  int N, Q;
  cin >> N >> Q;
  deque<int> deq;
  rep(i, N) {
    int a;
    cin >> a;
    deq.push_back(a);
  }
  
  rep(i, Q) {
    int type, x, y;
    cin >> type >> x >> y;
    if (x != 0) x--;
    if (y != 0) y--;
    
    if (type == 1) {
      int tmp = deq.at(x);
      deq.at(x) = deq.at(y);
      deq.at(y) = tmp;
    } else if (type == 2) {
      int tmp = deq.back();
      deq.pop_back();
      deq.push_front(tmp);
    } else if (type == 3) {
      cout << deq.at(x) << endl;
    }
  }
}
