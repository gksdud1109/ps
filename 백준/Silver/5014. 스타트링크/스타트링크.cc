#include <bits/stdc++.h>
using namespace std;

int dist[1000002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int F, S, G, U, D;
  cin >> F >> S >> G >> U >> D;
  fill(dist+1, dist+F+1, -1);

  queue<int> Q;
  dist[S] = 0;
  Q.push(S); // 시작층
  while(!Q.empty()){
    int cur=Q.front(); Q.pop();
    for(auto nxt : {cur+U, cur-D}){
      if(nxt > F || nxt <= 0 || dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      Q.push(nxt);
    }
  }

  if(dist[G]==-1) cout << "use the stairs";
  else cout << dist[G];
}