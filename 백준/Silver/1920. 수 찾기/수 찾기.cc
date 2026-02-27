#include <bits/stdc++.h>
using namespace std;

int a[100005];
int N;

int binarysearch(int target){
  int st=0;
  int en=N-1;
  while(st<=en){
    int mid = (st+en)/2;
    if(a[mid] < target)
      st = mid+1;
    else if(a[mid] > target)
      en = mid-1;
    else
      return 1;
  }
  return 0;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++) cin >> a[i];
  sort(a, a+N);
  int M; cin >> M;
  while(M--){
    int t;
    cin >> t;
    cout << binarysearch(t) << '\n';
  }
}