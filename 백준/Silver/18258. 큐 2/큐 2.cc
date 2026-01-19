#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

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
      if (Q.empty())
        cout << -1 << '\n';
      else
      {
        cout << Q.front() << '\n';
        Q.pop();
      }
    }
    else if (comm == "size")
      cout << Q.size() << '\n';
    else if (comm == "empty")
    {
      cout << Q.empty() << '\n';
    }
    else if (comm == "front")
    {
      if (Q.empty())
        cout << -1 << '\n';
      else
        cout << Q.front() << '\n';
    }
    else // comm == "back"
    {
      if (Q.empty())
        cout << -1 << '\n';
      else
        cout << Q.back() << '\n';
    }
  }
}