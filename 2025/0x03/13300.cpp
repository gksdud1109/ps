#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K, ans = 0;
  cin >> N >> K;
  int stu[2][7] = {};

  for (int i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    stu[a][b]++;
  }
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      // 배정에 필요한 만큼 방의 개수 추가
      ans += stu[i][j] / K;
      // 학생이 남을 경우, 하나의 방이 더 필요하므로 방의 개수 추가
      if (stu[i][j] % K)
        ++ans;
    }
  }
  cout << ans;
}