#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];
int N, M;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<M; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int num = 0;
  for(int i=1; i<=N; i++){
    if(vis[i]) continue;
    num++;
    queue<int> Q;
    Q.push(i);
    vis[i] = true;
    while(!Q.empty()){
      int cur = Q.front(); Q.pop();
      for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        Q.push(nxt);
        vis[nxt] = true;
      }
    }
  }
  cout << num;
}