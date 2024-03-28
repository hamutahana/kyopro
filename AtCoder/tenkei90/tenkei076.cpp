#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  vector<int64_t> A(N), B(2*N - 1);
  rep(i, N) cin >> A.at(i);
  rep(i, 2*N - 1) B.at(i) = A.at(i % N);
  
  int64_t total = 0;
  for (int64_t x : A) total += x;
  
  if (total % 10 != 0) {
    cout << "No" << endl;
    return 0;
  }
  
  int64_t target = total / 10;
  
  queue<int64_t> q;
  int64_t sum = 0;
  rep(i, 2*N - 1) {
    if (B.at(i) > target) {
      queue<int64_t> empty;
      swap(q, empty);
      sum = 0;
      continue;
    }
    
    q.push(B.at(i));
    sum += B.at(i);
    if (sum == target) {
      cout << "Yes" << endl;
      return 0;
    }
    
    while (sum > target) {
      int first_element = q.front();
      sum -= first_element;
      q.pop();
    }
  }
  
  cout << "No" << endl;
}
