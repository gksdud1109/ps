#include <bits/stdc++.h>
using namespace std;

int H[1003][4];
int D[1003][4];
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> H[i][1] >> H[i][2] >> H[i][3];
  
  D[1][1] = H[1][1];
  D[1][2] = H[1][2];
  D[1][3] = H[1][3];
  for(int i=2; i<=n; i++){
    D[i][1] = min(D[i-1][2],D[i-1][3]) + H[i][1];
    D[i][2] = min(D[i-1][1],D[i-1][3]) + H[i][2];
    D[i][3] = min(D[i-1][1],D[i-1][2]) + H[i][3];
  }

  cout << min({D[n][1],D[n][2],D[n][3]});
}