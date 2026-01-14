#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int N, M, ans = 0;
  cin >> N >> M;
  deque<int> D;

  for (int i = 1; i <= N; i++)
    D.push_back(i);

  while (M--)
  {
    int X;
    cin >> X;
    int index = find(D.begin(), D.end(), X) - D.begin(); // search
    while (D.front() != X)
    {
      if (D.size() - index > index)
      {
        D.push_back(D.front());
        D.pop_front();
      }
      else
      {
        D.push_front(D.back());
        D.pop_back();
      }
      ans++;
    }
    D.pop_front();
  }
  cout << ans;
}