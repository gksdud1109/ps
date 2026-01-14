#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio;
  cin.tie(0);
  stack<int> S;
  int K, sum = 0;
  cin >> K;
  while (K--)
  {
    int num;
    cin >> num;
    if (num == 0)
      S.pop();
    else
      S.push(num);
  }
  while (S.size() > 0)
  {
    sum += S.top();
    S.pop();
  }
  cout << sum;
}