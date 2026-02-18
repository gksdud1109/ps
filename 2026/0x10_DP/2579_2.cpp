#include <bits/stdc++.h>
using namespace std;

int S[305];
int N;
int D[305];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int tot = 0;
  for(int i=1; i<=N; i++){
    cin >> S[i];
    tot += S[i];
  }

  if(N <= 2){
    cout << tot;
    return 0;
  }

  D[1] = S[1]; D[2] = S[2]; D[3] = S[3];
  for(int i=4; i<= N-1; i++){
    D[i] = min(D[i-2], D[i-3])+S[i];
  }
  cout << tot - min(D[N-1], D[N-2]);
}