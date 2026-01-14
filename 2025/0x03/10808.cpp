#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  for (char a = 'a'; a <= 'z'; a++)
  {
    int count = 0;
    for (auto c : s)
    {
      if (a == c)
        count++;
    }
    cout << count << ' ';
  }
}