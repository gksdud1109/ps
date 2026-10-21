#include <bits/stdc++.h>
using namespace std;

int n, m, st;
vector<int> adj[1005];
bool vis[1005];

void dfs(int cur){
  vis[cur] = true;
  cout << cur << ' ';

  for(int nxt: adj[cur]){
    if(vis[nxt]) continue;
    dfs(nxt);
  }
}

void bfs(){
  queue<int> q;
  vis[st] = true;
  q.push(st);

  while(!q.empty()){
    int cur = q.front(); q.pop();

    cout << cur << ' ';
    for(int nxt : adj[cur]){
      if(vis[nxt]) continue;

      vis[nxt] = true;
      q.push(nxt);
    }
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> st;

    for(int i=0; i<m; i++){
      int a, b;
      cin >> a >> b;
      
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
      sort(adj[i].begin(), adj[i].end());

    dfs(st);
    cout << '\n';

    fill(vis, vis+n+1, false);

    bfs();
    cout <<'\n';

    return 0;
}
