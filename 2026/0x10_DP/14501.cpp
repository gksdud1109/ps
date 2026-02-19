#include <bits/stdc++.h>
using namespace std;

int T[20];
int P[20];
int D[20];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for(int i=1; i<= N; i++) cin >> T[i] >> P[i];

  for(int i=N; i>=1; i--){
    if(i+T[i] <= N+1){
      D[i] = max(D[i+T[i]]+P[i], D[i+1]);
    }
    else D[i] = D[i+1];
  }
  cout << *max_element(D, D+N+1);
}