#include <bits/stdc++.h>
using namespace std;
#define end first
#define st second

int n;
pair<int,int> S[100005]; // {end, start}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;

  for(int i=0; i<n; i++)
    cin >> S[i].st >> S[i].end;
  sort(S, S+n);

  int ans=0;
  int t=0;
  for(int i=0; i<n; i++){
    if(t>S[i].st) continue;
    ans++;
    t = S[i].end;
  }
  cout << ans;
}