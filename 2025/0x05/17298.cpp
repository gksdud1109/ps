#include <bits/stdc++.h>
using namespace std;

int NGE[1000000];
int arr[1000000];
int main(void)
{
  int N, index = 0;
  stack<int> S;
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  for (int i = N - 1; i >= 0; i--)
  {
    while (!S.empty() && S.top() <= arr[i])
      S.pop();
    if (S.empty())
      NGE[i] = -1;
    else
      NGE[i] = S.top();
    S.push(arr[i]);
  }

  for (int i = 0; i < N; i++)
    cout << NGE[i] << ' ';
}