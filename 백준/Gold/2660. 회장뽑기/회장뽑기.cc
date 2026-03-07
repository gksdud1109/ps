#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[52];
vector<pair<int, int>> candsc;
int score[52];

int bfs(int st){
  queue<int> Q;
  int dist[52];
  fill(dist, dist+N+1, -1);

  dist[st]=0;
  Q.push(st);
  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    for(int nxt : adj[cur]){
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      Q.push(nxt);
    }
  }

  int val= *max_element(dist+1, dist+N+1);
  if(val==0) return 100;
  return val;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  int u=0, v=0;
  while(u!=-1 && v!=-1){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i=1; i<=N; i++)
    score[i] = bfs(i);

  int mnscore = *min_element(score+1, score+N+1);
  vector<int> candidate;
  for(int i=1; i<=N; i++){
    if(score[i] == mnscore)
      candidate.push_back(i);
  }

  cout << mnscore << ' ' << candidate.size() << '\n';
  for(int c : candidate) cout << c << ' ';
}