#include <bits/stdc++.h>
using namespace std;

const int MXN = 10e5 + 10;
int N, R, Q, U, V, q, subTreeSize[MXN];
vector<int> adj[MXN];
vector<bool> vis(MXN);
int countSubTreeNode(int cur){
  vis[cur] = true;
  for(auto nxt: adj[cur]){
    if(vis[nxt]) continue;
    subTreeSize[cur] += countSubTreeNode(nxt);
  }
  subTreeSize[cur]++;
  return subTreeSize[cur];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> R >> Q;

  for(int i=0; i<N-1; i++){
    cin >> U >> V;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  countSubTreeNode(R);
  while(Q--){
    cin >> q;
    cout << subTreeSize[q] << '\n';
  }
}