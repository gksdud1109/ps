#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[5];
  int even = 0, x;
  for (int i = 0; i < 5; i++)
  {
    cin >> x;
    arr[i] = x;
    even += x;
  }
  sort(arr, arr + 5);

  cout << even / 5 << "\n";
  cout << arr[2];
}