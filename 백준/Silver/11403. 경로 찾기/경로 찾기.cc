#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
bool vis[105];
int N;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      int v; cin >> v;
      if(v == 1)
        adj[i].push_back(j);
    }
  }

  for(int i=1; i<=N; i++){
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(i);

    while(!Q.empty()){
      int cur = Q.front(); Q.pop();

      for(int nxt: adj[cur]){
        if(!vis[nxt]){
          vis[nxt] = true;
          Q.push(nxt);
        }
      }
    }

    for(int j=1; j<=N; j++){
      if(vis[j]) cout << 1 << " ";
      else cout << 0 << " ";
    }
    cout << '\n';
  }
}