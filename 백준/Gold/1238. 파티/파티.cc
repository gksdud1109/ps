#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int N, M;
vector<pair<int, int>> adj[1002];

int solve(int st, int en){
  int d[1002];
  fill(d, d+N+1, INF);
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

  d[st] = 0;
  pq.push({0, st});
  while(!pq.empty()){
    int u, v, w, dw;
    tie(w, u) = pq.top(); pq.pop();
    if(d[u] != w) continue;
    for(auto nxt: adj[u]) {
      tie(dw, v) = nxt;
      if(dw + w < d[v]){
        d[v] = dw + w;
        pq.push({d[v], v});
      }
    }
  }
  return d[en];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int en;
  cin >> N >> M >> en;

  int u, v, w;
  while(M--){
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  int ans = 0;
  for(int st=1; st<=N; st++)
    ans = max(ans, solve(st,en)+solve(en, st));
  cout << ans;
}