#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int64_t total_sum = 0;
  int gap_count = S.size() - 1;
  for (int i = 0; i < (1 << gap_count); i++) {
    int64_t sum = 0;
    vector<int64_t> L(0);
    string tmp = string(1, S.at(0));
    for (int j = 0; j < gap_count; j++) {
      if ((i & (1 << j)) != 0) {
        L.push_back(stoll(tmp));
        tmp = "";
      }
      tmp += S.at(j+1);
    }
    L.push_back(stoll(tmp));
    
    for (int64_t x : L) sum += x;
    total_sum += sum;
  }
  
  cout << total_sum << endl;
}
