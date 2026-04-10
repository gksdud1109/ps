#include <bits/stdc++.h>
using namespace std;

const int MX = 100;
const int INF = 0x7f7f7f7f;

vector<int> adj[MX + 2];
int dist[MX + 2];

int mn = INF, ans;

int bfs(int st) {
  queue<int> q;
  int sum = 0;
  dist[st] = 0;
  q.push(st);
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      sum += dist[nxt];
      q.push(nxt);
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++) {
    fill(dist, dist+n+1, -1);
    int sum = bfs(i);
    if(sum >= mn) continue;
    mn = sum;
    ans = i;
  }
  cout << ans;
}