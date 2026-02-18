#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll D[100][2];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  D[1][1] = 1LL;
  for(int i=2; i<=N; i++){
    D[i][0] = D[i-1][0] + D[i-1][1]; // 0다음 0이오는 경우 + 0다음 1
    D[i][1] = D[i-1][0]; // 1다음은 항상 0
  }

  cout << D[N][0] + D[N][1];
}