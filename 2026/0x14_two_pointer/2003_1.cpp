#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
ll pf_sum[10005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  pf_sum[0] = 0;
  for(int i=1; i<=N; i++) cin >> pf_sum[i], pf_sum[i] += pf_sum[i-1];

  int st=0, en=0, ans=0;

  while(en <= N){
    ll csum = pf_sum[en] - pf_sum[st];
    if(csum <= M){
      if(csum == M) ans++;
      en++;
    }
    else st++;
  }

  cout << ans;
  return 0;
}