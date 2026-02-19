#include <bits/stdc++.h>
using namespace std;

int T, W;
int a[1005];
int D[1005][32][3]; // D[i][j][k]: i:현재시간, j:이동횟수, k:나무번호

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T >> W;
  for(int i=1; i<=T; i++)
    cin >> a[i];

  for(int i=1; i<=T; i++){
    D[i][0][1] = D[i-1][0][1] + (a[i] == 1 ? 1 : 0);
    for(int j=1; j<=W; j++){
      if(i < j) break; // 현지 시간보다 많이 이동한 경우
      if(a[i] == 1){
        D[i][j][1] = max(D[i-1][j-1][2], D[i-1][j][1]) +1;
        D[i][j][2] = max(D[i-1][j-1][1], D[i-1][j][2]);
      }
      else {
        D[i][j][1] = max(D[i-1][j-1][2], D[i-1][j][1]);
        D[i][j][2] = max(D[i-1][j-1][1], D[i-1][j][2])+1;
      }
    }
  }

  int ans =0;
  for(int j=0; j<=W; j++)
    ans = max({ans, D[T][j][1], D[T][j][2]});

  cout << ans;
}