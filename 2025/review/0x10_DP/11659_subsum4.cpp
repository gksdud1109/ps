#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100005], D[100004];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i=1; i<=N; i++) {
    cin >> arr[i];
    D[i] = D[i-1] + arr[i];
  }

  while(M--){
    int i, j;
    cin >> i >> j;
    cout << D[j]-D[i-1] << '\n';
  }
}