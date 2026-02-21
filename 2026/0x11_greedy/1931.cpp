#include <bits/stdc++.h>
using namespace std;

int N;
pair<int,int> S[100005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++) 
    cin >> S[i].second >> S[i].first;
  sort(S, S+N);

  int ans = 0;
  int t = 0;
  for(int i=0; i<N; i++){
    if(t > S[i].second) continue;
    ans++;
    t = S[i].first;
  }
  cout << ans;
}