#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, ans = 0;
  int numSet[10] = {0};

  cin >> N;
  while (N > 0)
  {
    numSet[N % 10]++;
    N /= 10;
  }
  for (int i = 0; i < 10; i++)
  {
    if (i == 6 || i == 9)
      continue;
    ans = max(ans, numSet[i]);
  }
  ans = max(ans, (numSet[6] + numSet[9] + 1) / 2);
  cout << ans;
}