#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
int dist[505];
int N, M;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  int ans = 0;
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  queue<int> Q;
  Q.push(1); dist[1] = 1;

  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    if(dist[cur] > 2) continue;
    for(auto nxt : adj[cur]){
      if(dist[nxt] > 0) continue;
      dist[nxt] = dist[cur] + 1;
      Q.push(nxt);
      ans++;
    }
  }
  cout << ans << '\n';
}