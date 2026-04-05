#include <bits/stdc++.h>
using namespace std;
#define dst first
#define vtx second

int v, e, st, en;

vector<pair<int,int>> adj[1005];
const int INF = 0x3f3f3f3f;
int d[1005];
int pre[1005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> v >> e;
  fill(d, d+v+1, INF);
  while(e--){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  cin >> st >> en;

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  d[st] = 0;
  pq.push({d[st], st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.vtx] != cur.dst) continue;
    for(auto nxt : adj[cur.vtx]){
      if(d[nxt.vtx] <= d[cur.vtx]+nxt.dst) continue;
      d[nxt.vtx] = d[cur.vtx]+nxt.dst;
      pq.push({d[nxt.vtx], nxt.vtx});
      pre[nxt.vtx] = cur.vtx; // 경로 복원
    }
  }

  cout << d[en] << '\n';
  vector<int> path;
  int cur = en;
  while(cur!=st){
    path.push_back(cur);
    cur = pre[cur];
  }

  path.push_back(cur);
  reverse(path.begin(), path.end());
  cout << path.size() << '\n';
  for(auto x : path) cout << x << ' ';
}