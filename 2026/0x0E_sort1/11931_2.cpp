#include <bits/stdc++.h>
using namespace std;

const int MXN = 2'000'000, HALF = MXN / 2;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<bool> isnum(MXN + 2);
  int N, t;
  cin >> N;
  while (N--) {
    cin >> t;
    isnum[t + HALF] = true;
  }
  for (int i = MXN; i >= 0; i--)
    if (isnum[i]) cout << i - HALF << '\n';
}
// 입력 100만번 + 배열 처음부터 끝까지 훑기 200만번
// 주어진 수의 범위가 MXN안에서 끝나기때문에,
// bool은 1비트 -> 2000000비트 크기에서 메모리 제한에 안걸림