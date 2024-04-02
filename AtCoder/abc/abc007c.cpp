#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using vb = vector<bool>;
using vbb = vector<vb>;
#define rep(i, n) for (int i = 1; i <= (n); i++)

int main() {
  const vi direct_y = { -1, 0, 1, 0 };
  const vi direct_x = { 0, 1, 0, -1 };
  
  int H, W;
  cin >> H >> W;
  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;
  vbb checked(H+2, vb(W+2, true));
  vii count(H+2, vi(W+2, -1));
  rep(i, H) {
    rep(j, W) {
      char c;
      cin >> c;
      if (c == '.') checked.at(i).at(j) = false;
    }
  }
  
  queue<int> qy;
  queue<int> qx;
  
  count.at(sy).at(sx) = 0;
  qy.push(sy); qx.push(sx);
  checked.at(sy).at(sx) = true;
  
  while (!qy.empty() && !qx.empty()) {
    int pos_y = qy.front(), pos_x = qx.front();
    qy.pop(); qx.pop();
    for (int i = 0; i < 4; i++) {
      int next_y = pos_y + direct_y.at(i);
      int next_x = pos_x + direct_x.at(i);
      if (!checked.at(next_y).at(next_x)) {
        count.at(next_y).at(next_x) = count.at(pos_y).at(pos_x) + 1;
        qy.push(next_y); qx.push(next_x);
        checked.at(next_y).at(next_x) = true;
      }
    }
  }
  
  cout << count.at(gy).at(gx) << endl;
}

