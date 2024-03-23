#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  
  // 壁に対して、人とゴールが同じ側に存在する場合
  // 壁を越えずにゴールできる
  if ((0 - Y) * (X - Y) > 0) {
    cout << abs(X) << endl;
    return 0;
  }
  
  // 壁に対して、ゴールとハンマーが反対側に存在する場合
  // ハンマーを取りに行って壁を破壊してゴールする
  if ((X - Y) * (Z - Y) < 0) {
    cout << abs(Z) + abs(Z - X) << endl;
    return 0;
  }
  
  // 壁に対して、ゴールとハンマーが同じ側に存在する場合
  // ハンマーを取りに行けないのでゴールできない
  cout << -1 << endl;
}
