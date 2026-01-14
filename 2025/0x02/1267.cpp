#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int call_n, ysum = 0, msum = 0;
  cin >> call_n;

  int arr[call_n];

  for (int i = 0; i < call_n; i++)
    cin >> arr[i];

  for (int i = 0; i < call_n; i++)
  {
    ysum += ((arr[i] / 30) + 1) * 10;
    msum += ((arr[i] / 60) + 1) * 15;
  }
  if (ysum < msum)
    cout << "Y " << ysum;
  else if (msum < ysum)
    cout << "M " << msum;
  else
    cout << "Y M " << ysum;
}