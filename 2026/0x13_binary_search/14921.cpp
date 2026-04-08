#include <bits/stdc++.h>
using namespace std;

int N;
int A[100005];
int ans = 1e9+1;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  int st = 0, en = N-1;
  while(st<en){
    int val = A[st] + A[en];
    if(abs(val) < abs(ans)) ans = val;
    if(val<0) st++;
    else en--;
  }
  cout << ans;
}