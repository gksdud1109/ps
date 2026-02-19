#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll D[101][10];
const int mod = 1000000000;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  
  for(int i=1; i<=9; i++) D[1][i] = 1;

  for(int i=2; i<=N; i++){
    for(int k=0; k<=9; k++){
      if(k!=0) D[i][k] += D[i-1][k-1];
      if(k!=9) D[i][k] += D[i-1][k+1];
      D[i][k] %= mod;
    }
  }

  ll ans = 0;
  for(int i=0; i<=9; i++)
    ans += D[N][i];

  ans %= mod;
  cout << ans;
}