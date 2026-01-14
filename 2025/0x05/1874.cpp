#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio;
  cin.tie(0);

  stack<int> S;
  int n, count = 1;
  cin >> n;
  string ans;

  while (n--)
  {
    int t;
    cin >> t;
    while (count <= t)
    {
      S.push(count++);
      ans += "+\n";
    }
    if (S.top() != t)
    {
      cout << "NO\n";
      return 0;
    }
    S.pop();
    ans += "-\n";
  }
  cout << ans;
}