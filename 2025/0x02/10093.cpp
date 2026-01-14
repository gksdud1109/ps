#include <bits/stdc++.h>
using namespace std;

long long a, b;
// in problem constraint, 1 <= A, B <= 10^15
// int can only express near 2*10^10

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  if (a > b)
    swap(a, b);
  if (a == b || b - a == 1)
    cout << 0;
  else
  {
    cout << b - a - 1 << "\n";

    for (long long i = a + 1; i < b; i++)
    {
      cout << i << ' ';
    }
  }
}