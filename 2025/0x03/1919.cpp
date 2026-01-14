#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  int alpha[26] = {};
  int count = 0;
  cin >> a >> b;

  for (auto c : a)
    alpha[c - 'a']++;
  for (auto c : b)
    alpha[c - 'a']--;

  for (auto c : alpha)
  {
    if (c < 0)
      count += (-c);
    else
      count += c;
  }

  cout << count;
}