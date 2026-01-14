#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  if (t >= 90)
    cout << 'A';
  else if (80 <= t && t < 90)
    cout << 'B';
  else if (70 <= t && t < 80)
    cout << 'C';
  else if (60 <= t && t < 70)
    cout << 'D';
  else
    cout << 'F';
}