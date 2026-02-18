#include <bits/stdc++.h>
using namespace std;

int D[10005];
int mod = 10007;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N; cin >> N;
  D[1] = 1;
  D[2] = 2;

  for(int i=3; i<=N; i++) D[i] = (D[i-1]+D[i-2]) %mod;
  cout << D[N];
}