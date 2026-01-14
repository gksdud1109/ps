#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int count[201] = {0};
  int N, v, t;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> t;
    count[t + 100]++;
  }
  cin >> v; // 찾으려고 하는 정수
  cout << count[v + 100]++;
}