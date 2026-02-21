#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[105], V[105];
int D[100005]; // D[j]: 배낭의 허용 무게가 j일때 담을 수 있는 최대 가치

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  for(int i=1; i<=N; i++){
    cin >> W[i] >> V[i];
  }

  for(int i=1; i<=N; i++){
    for(int j=K; j>=W[i]; j--){
      D[j] = max(D[j], D[j-W[i]] + V[i]);
    }
  }

  cout << D[K];
  return 0;
}