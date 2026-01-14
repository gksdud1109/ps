#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  string s;
  int M;

  cin >> s;
  list<char> charList;
  for (auto c : s)
    charList.push_back(c);
  list<char>::iterator cursor = charList.end();

  cin >> M;
  while (M--)
  {
    char op;
    cin >> op;

    if (op == 'P')
    {
      char add;
      cin >> add;
      charList.insert(cursor, add);
    }
    else if (op == 'L')
    {
      if (cursor != charList.begin())
        cursor--;
    }
    else if (op == 'D')
    {
      if (cursor != charList.end())
        cursor++;
    }
    else
    {
      if (cursor != charList.begin())
      {
        cursor--;
        cursor = charList.erase(cursor);
      }
    }
  }
  for (auto c : charList)
    cout << c;
}