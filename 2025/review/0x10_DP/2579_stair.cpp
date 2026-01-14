#include <bits/stdc++.h>
using namespace std;

int D[305][3];
int score[305];
int T;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;

  for(int i=1; i<=T; i++){
    cin >> score[i];
  }

  if(T == 1){
    cout << score[1];
    return 0;
  }
  D[1][1] = score[1]; D[1][2] = 0;
  D[2][1] = score[2]; D[2][2] = score[1]+score[2];
  for(int i=3; i<=T; i++){
    D[i][1] = max(D[i-2][1], D[i-2][2])+score[i];
    D[i][2] = D[i-1][1]+score[i];
  }
  cout << max(D[T][1], D[T][2]);
}