#include <bits/stdc++.h>
using namespace std;

int a[5000005];
int N;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) cin >> a[i];
  sort(a, a+N);
  int M; cin >> M;
  while(M--){
    int t; cin >> t;
    cout << upper_bound(a, a+N, t) - lower_bound(a,a+N, t) << '\n';
  }
}