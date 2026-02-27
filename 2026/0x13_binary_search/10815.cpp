#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[500005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N);

  cin >> M;
  while(M--){
    int target; cin >> target;
    cout << binary_search(arr, arr+N, target) << ' ';
  }
}