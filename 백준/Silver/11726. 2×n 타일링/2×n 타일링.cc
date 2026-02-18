#include <bits/stdc++.h>
using namespace std;

int D[1005];
int mod=10007;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  D[1]=1; D[2]=2;
  for(int i=3; i<=n; i++)
    D[i] = (D[i-1]+D[i-2])%mod;

  cout << D[n];
}