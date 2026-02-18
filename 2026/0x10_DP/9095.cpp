#include <bits/stdc++.h>
using namespace std;

int T;
int D[15];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;

  D[1]=1; D[2]=2; D[3]=4;
  for(int i=4; i<11; i++)
    D[i] = D[i-1] + D[i-2] + D[i-3];

  while(T--){
    int N;
    cin >> N;
    cout << D[N] << '\n';
  }
}