#include <bits/stdc++.h>
using namespace std;

const int MXN = 510;
vector<int> adj[MXN];
bool vis[MXN], isTree;
int N, M, u, v, tc, trees;

// 사이클 탐지, tree란 사이클이 없어야 함.
void dfs(int cur, int prev){
  for(int nxt: adj[cur]){
    if(nxt == prev) // next가 부모(prev)일 경우 건너뜀
      continue;
    // 트리일 경우 자식은 반드시 이전에 방문한 적이 없어야하고,
    // 이전에 방문을 했다면 현재 보고 있는 connected component가 트리가 아님을 의미
    if(vis[nxt]) { 
      isTree = false;
      continue;
    }
    vis[nxt] = true;
    dfs(nxt, cur);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1){
    cin >> N >> M;
    if(!N && !M) break;

    fill(vis, vis+N+1, 0);
    for(int i=1; i<=N; i++) adj[i].clear();
    trees = 0;
    while(M--){
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(int i=1; i<=N; i++){
      if(vis[i]) continue;
      vis[i] = true;
      isTree = true;
      dfs(i, -1);
      trees += isTree;
    }
    cout << "Case " << ++tc << ": ";
    if(!trees)
      cout << "No trees." << '\n';
    else if (trees == 1)
      cout << "There is one tree." << '\n';
    else
      cout << "A forest of " << trees << " trees." << '\n';
  }
}