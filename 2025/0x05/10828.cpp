#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int stack[100001];
  int N, pos = 0;

  cin >> N;

  while (N--)
  {
    string command;
    cin >> command;
    if (command == "push")
    {
      int X;
      cin >> X;
      stack[pos++] = X;
    }
    else if (command == "pop")
    {
      if (pos > 0)
        cout << stack[--pos] << '\n';
      else
        cout << -1 << '\n';
    }
    else if (command == "size")
      cout << pos << '\n';
    else if (command == "empty")
    {
      if (pos == 0)
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
    else if (command == "top")
    {
      if (pos > 0)
        cout << stack[pos - 1] << '\n';
      else
        cout << -1 << '\n';
    }
  }
}