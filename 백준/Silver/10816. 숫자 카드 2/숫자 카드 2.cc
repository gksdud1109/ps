#include <bits/stdc++.h>
using namespace std;

int arr[500005];
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];
  sort(arr, arr+n);
  int m;
  cin >> m;
  while(m--){
    int t;
    cin >> t;
    cout << upper_bound(arr, arr+n, t)-lower_bound(arr, arr+n, t)<<'\n';
  }
}