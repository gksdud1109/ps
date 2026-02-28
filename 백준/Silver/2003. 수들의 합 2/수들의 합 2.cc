#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[10005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> a[i];

  int st=0, en=0, tmpSum =0, ans=0;

  while(1){
    if(tmpSum >= M){
      if(tmpSum == M) ans++;
      tmpSum -= a[st++];
    }
    else if(en == N) break;
    else{ // tmpSum < M
      tmpSum += a[en++];
    }
  }
  cout << ans;
  return 0;
}