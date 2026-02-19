#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll D[100];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N; cin >> N;

  D[1]=1; D[2]=1;
  for(int i=3; i<=N; i++)
    D[i] = D[i-1]+D[i-2];

  cout << D[N];
}