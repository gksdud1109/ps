#include <bits/stdc++.h>
using namespace std;

int N;
int w[100005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++) cin >> w[i];
  sort(w, w+N);
  int ans = 0;
  for(int i=1; i<=N; i++)
    ans = max(ans, w[N-i]*i);
  
  cout << ans;
}