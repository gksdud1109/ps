#include <bits/stdc++.h>
using namespace std;

int numCard[21];

void cardSwitch(int a, int b)
{
  for (int i = 0; i < (b - a + 1) / 2; i++)
    swap(numCard[a + i], numCard[b - i]);
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 20; i++)
    numCard[i] = i;

  for (int i = 1; i <= 10; i++)
  {
    int a, b;
    cin >> a >> b;
    cardSwitch(a, b);
  }

  for (int i = 1; i <= 20; i++)
    cout << numCard[i] << ' ';
}
