#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  
  // 壁を越える必要がない場合
  if ((Y > 0 && X < Y) || (Y < 0 && X > Y)) {
    cout << abs(X) << endl;
    return 0;
  }
  
  // 壁に対して、ゴールとハンマーが反対側に存在する場合
  if ((X - Y) * (Z - Y) < 0) {
    cout << abs(Z) + abs(Z - X) << endl;
    return 0;
  }
  
  // 壁に対して、ゴールとハンマーが同じ側に存在する場合
  cout << -1 << endl;
}
