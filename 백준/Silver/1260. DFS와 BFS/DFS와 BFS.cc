#include <bits/stdc++.h>
using namespace std;

int N, M, st;
vector<int> adj[1005];
bool vis[1005];

// 비재귀 dfs
void dfs1(){
  stack<int> s;
  s.push(st);
  while(!s.empty()){
    int cur = s.top(); s.pop();
    if(vis[cur]) continue;
    vis[cur] = true;
    cout << cur << ' ';
    for(int i=0; i<adj[cur].size(); i++){
      int nxt = adj[cur][adj[cur].size()-1-i];
      if(vis[nxt]) continue;
      s.push(nxt);
    }
  }
}

// 재귀 dfs
void dfs2(int cur){
  vis[cur] = true;
  cout << cur << ' ';
  for(auto nxt : adj[cur]){
    if(vis[nxt]) continue;
    dfs2(nxt);
  }
}

void bfs(){
  queue<int> q;
  q.push(st);
  vis[st] = true;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> st;

  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1; i<=N; i++)
    sort(adj[i].begin(), adj[i].end());
  
  dfs1();
  cout << '\n';
  fill(vis+1, vis+N+1, false);
  bfs();
}