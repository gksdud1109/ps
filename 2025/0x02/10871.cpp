#include <bits/stdc++.h>
using namespace std;

int n, x, a[10005];
int main(void)
{
  // C와 C++의 표준 stream 동기화를 비활성화 -> C++ 스타일만 사용할수 있는 대신,
  // 기존 동기화 과정에서 필요하던 시간이 절약되어 입출력 속도가 빨라지는 효과
  // 기존 C의 표준 입출력인 scanf,printf, getchar를 사용할 수 없음
  ios::sync_with_stdio(0);
  cin.tie(0);

  //
  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    if (a[i] < x)
      cout << a[i] << ' ';
}