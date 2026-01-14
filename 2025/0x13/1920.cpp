#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int N;

int binary_search(int target){
  int st=0;
  int en=N-1;

  while(st <=en){
    int mid = (st+en)/2;
    if(arr[mid] < target)
      st = mid+1;
    else if(arr[mid] > target)
      en = mid-1;
    else
      return 1;
  }
  return 0;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int M;
  cin >> N;

  for(int i=0; i<N; i++){
    cin >> arr[i];
  }
  cin >> M;
  sort(arr, arr+N);

  while(M--){
    int t;
    cin >> t;
    cout << binary_search(t) << '\n';
  }
}