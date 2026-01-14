#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  stack<int> S;
  int N;
  cin >> N;

  while (N--)
  {
    string command;
    cin >> command;
    if (command == "push")
    {
      int X;
      cin >> X;
      S.push(X);
    }
    else if (command == "pop")
    {
      if (S.empty())
        cout << -1 << '\n';
      else
      {
        cout << S.top() << '\n';
        S.pop();
      }
    }
    else if (command == "size")
      cout << S.size() << '\n';
    else if (command == "empty")
      cout << (int)S.empty() << '\n';
    else
    { // top
      if (S.empty())
        cout << -1 << '\n';
      else
        cout << S.top() << '\n';
    }
  }
}