#include <bits/stdc++.h>
using namespace std;

const int LIM = 100001;
int dist[LIM + 2];
int prePos[LIM + 2];
queue<int> Q;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K; cin >> N >> K;
  fill(dist, dist+LIM, -1);
  dist[N]=0;
  prePos[N] = N;
  Q.push(N);

  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    for(int nx : {cur+1, cur-1, 2*cur}){
      if(nx < 0 || LIM <= nx) continue;
      if(dist[nx] != -1) continue;
      dist[nx] = dist[cur] +1;
      prePos[nx] = cur;
      Q.push(nx);
    }
  }
  cout << dist[K] << '\n';
  vector<int> path;
  for(int x=K; ; x=prePos[x]){
    path.push_back(x);
    if(x==N) break;
  }
  reverse(path.begin(), path.end());
  for(int x: path) cout << x << ' ';
}