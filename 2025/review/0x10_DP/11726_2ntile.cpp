#include <bits/stdc++.h>
using namespace std;

int tile[1005];
int mod=10007;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  tile[1] = 1; tile[2] = 2;

  for(int i=3; i<=n; i++)
    tile[i] = (tile[i-1]+tile[i-2])%mod;
  cout << tile[n];
}