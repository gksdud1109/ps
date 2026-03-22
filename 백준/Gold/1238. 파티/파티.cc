#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, X;

// 원래 지도 (X -> i, 집에 돌아갈 때 사용)
vector<pair<int, int>> adj[1002];
// 간선이 뒤집힌 지도(i -> X, 파티장 갈 때 사용)
vector<pair<int, int>> rev_adj[1002];

vector<int> dijkstra(int st, const vector<pair<int,int>> graph[]){
  vector<int> d(N+1, INF);
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

  d[st] = 0;
  pq.push({0, st});

  while(!pq.empty()){
    auto [w, u] = pq.top(); pq.pop();
    if(d[u] != w) continue;

    for(auto [dw, v] : graph[u]){
      if(d[u]+dw < d[v]){
        d[v] = d[u] + dw;
        pq.push({d[v], v});
      }
    }
  }
  return d;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> X;

  while(M--){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v}); // 정방향 저장
    rev_adj[v].push_back({w, u}); // 역방향 저장
  }

  vector<int> dist_to_home = dijkstra(X, adj);
  vector<int> dist_to_party = dijkstra(X, rev_adj);

  int ans = 0;
  for(int i=1; i<=N; i++){
    if(dist_to_party[i] == INF || dist_to_home[i] == INF) continue;
    ans = max(ans, dist_to_party[i] + dist_to_home[i]);
  }
  cout << ans;
}