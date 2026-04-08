#include <bits/stdc++.h>
using namespace std;

int N;
int A[10002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);

  long long ans = 0;

  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
      auto ub = upper_bound(A+j+1, A+N, -A[i]-A[j]);
      auto lb = lower_bound(A+j+1, A+N, -A[i]-A[j]);
      ans += ub - lb;
    }
  }

  cout << ans;
}