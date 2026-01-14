#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  deque<int> D;

  while (N--)
  {
    string q;
    cin >> q;

    if (q == "push_front")
    {
      int X;
      cin >> X;
      D.push_front(X);
    }
    else if (q == "push_back")
    {
      int X;
      cin >> X;
      D.push_back(X);
    }
    else if (q == "pop_front")
    {
      if (D.empty())
        cout << -1 << '\n';
      else
      {
        cout << D.front() << '\n';
        D.pop_front();
      }
    }
    else if (q == "pop_back")
    {
      if (D.empty())
        cout << -1 << '\n';
      else
      {
        cout << D.back() << '\n';
        D.pop_back();
      }
    }
    else if (q == "size")
      cout << D.size() << '\n';
    else if (q == "empty")
    {
      if (D.empty())
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
    else if (q == "front")
    {
      if (D.empty())
        cout << -1 << '\n';
      else
        cout << D.front() << '\n';
    }
    else // q == "back"
    {
      if (D.empty())
        cout << -1 << '\n';
      else
        cout << D.back() << '\n';
    }
  }
}