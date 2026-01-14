#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, sum = 0, min = 101;

  for (int i = 0; i < 7; i++)
  {
    cin >> x;
    if (x % 2 != 0)
    {
      sum += x;
      if (x < min)
        min = x;
    }
  }
  if (sum)
    cout << sum << '\n'
         << min;
  else
    cout << "-1";
}