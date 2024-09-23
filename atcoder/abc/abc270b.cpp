// https://atcoder.jp/contests/abc270/tasks/abc270_b
#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  
  // 壁に対して人とゴールが同じ側にある場合
  // 壁を越えずにゴールできる
  if ((0 - Y) * (X - Y) > 0) {
    cout << abs(X) << endl;
    return 0;
  }
  
  // 以下、壁に対して人とゴールが反対側にある場合
  
  // 壁に対して人とハンマーが同じ側にある場合
  // ハンマーを取りに行って壁を破壊してゴールする
  if ((0 - Y) * (Z - Y) > 0) {
    cout << abs(Z) + abs(Z - X) << endl;
    return 0;
  }
  
  // 以下、壁に対してハンマーとゴールが同じ側にある場合
  // ハンマーを取りに行けないのでゴールできない
  cout << -1 << endl;
}
