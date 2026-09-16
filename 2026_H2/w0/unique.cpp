#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> s{4, 3, 3, 5, 1, 2, 3};
  s.erase(unique(s.begin(), s.end()), s.end());
  for (int i : s)
    cout << i << " ";
  cout << '\n';

  vector<int> s2{4, 3, 3, 5, 1, 2, 3};
  sort(s2.begin(), s2.end());
  s2.erase(unique(s2.begin(), s2.end()), s2.end());
  for (int i : s2)
    cout << i << " ";
  cout << '\n';
}