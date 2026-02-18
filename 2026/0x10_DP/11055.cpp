#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1005];
int D[1005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=1; i<=N; i++){
    cin >> arr[i];
    D[i] = arr[i];
  }

  for(int i=1; i<=N; i++){
    for(int j=1; j<=i; j++){
      if(arr[j] < arr[i]) D[i] = max(D[i], D[j]+arr[i]);
    }
  }
  cout << *max_element(D, D+N+1);
}