#include <bits/stdc++.h>
using namespace std;

string board[1002];

int dist[12][1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<tuple<int,int,int>> Q;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, K; cin >> N >> M >> K;

  for(int i=0; i<N; i++)
    cin >> board[i];

  Q.push({0,0,0});
  dist[0][0][0] = 1;
  while(!Q.empty()){
    auto [w, curx, cury] = Q.front(); Q.pop();

    if(curx == N-1 && cury == M-1){
      cout << dist[w][curx][cury] << '\n';
      return 0;
    }

    for(int dir=0; dir<4; dir++){
      int nx = curx + dx[dir];
      int ny = cury + dy[dir];
      if(nx<0 || nx>=N || ny<0 || ny >= M) continue;
      int nw = w;
      if(board[nx][ny] == '1') nw++;
      if(nw > K || dist[nw][nx][ny] > 0) continue;
      dist[nw][nx][ny] = dist[w][curx][cury] + 1;
      Q.push({nw, nx, ny});
    }
  }

  cout << -1;
}