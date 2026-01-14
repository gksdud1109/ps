#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int testCase;
  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    string s;
    list<char> L, result = {};
    cin >> s;
    for (auto c : s)
      L.push_back(c);

    list<char>::iterator cursor = result.begin();
    for (list<char>::iterator it = L.begin(); it != L.end(); it++)
    {
      if (*it == '<')
      {
        if (cursor != result.begin())
          cursor--;
      }
      else if (*it == '>')
      {
        if (cursor != result.end())
          cursor++;
      }
      else if (*it == '-')
      {
        if (cursor != result.begin())
        {
          cursor--;
          cursor = result.erase(cursor);
        }
      }
      else
      {
        result.insert(cursor, *it);
      }
    }
    for (auto c : result)
      cout << c;

    cout << '\n';
  }
}