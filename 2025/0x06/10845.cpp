#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  queue<int> Q;

  int N;
  cin >> N;

  while (N--)
  {
    string comm;
    cin >> comm;

    if (comm == "push")
    {
      int X;
      cin >> X;
      Q.push(X);
    }
    else if (comm == "pop")
    {
      if (!Q.empty())
      {
        cout << Q.front() << "\n";
        Q.pop();
      }
      else
        cout << -1 << "\n";
    }
    else if (comm == "size")
      cout << Q.size() << "\n";
    else if (comm == "empty")
    {
      if (Q.empty())
        cout << 1 << "\n";
      else
        cout << 0 << "\n";
    }
    else if (comm == "front")
    {
      if (Q.empty())
        cout << -1 << "\n";
      else
        cout << Q.front() << "\n";
    }
    else // comm == "back"
    {
      if (Q.empty())
        cout << -1 << "\n";
      else
        cout << Q.back() << "\n";
    }
  }
}