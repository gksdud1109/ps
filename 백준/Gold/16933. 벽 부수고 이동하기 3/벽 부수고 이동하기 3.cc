#include <bits/stdc++.h>
using namespace std;

string board[1002];

int dist[1002][1002][12][2];
queue<tuple<int,int,int,int>> Q;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, K; cin >> N >> M >> K;

  for(int i=0; i<N; i++)
    cin >> board[i];
  Q.push({0,0,0,0});
  dist[0][0][0][0] = 1;
  while(!Q.empty()) {
    auto [x, y, w, t] = Q.front(); Q.pop();
    if(x==N-1 && y==M-1) {
      cout << dist[x][y][w][t] << '\n';
      return 0;
    }

    for(int dir=0; dir<4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx<0 || nx>=N || ny<0 || ny>=M) continue;

      if(board[nx][ny] == '0'){
        int nw=w;
        int nt = 1-t;
        if(dist[nx][ny][nw][nt]>0) continue;
        dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;
        Q.push({nx, ny, nw, nt});
      }
      // 벽이 있는경우
      else {
        if(w==K) continue;
        if(t==0){
          int nw=w+1;
          int nt=1-t;
          if(dist[nx][ny][nw][nt] > 0) continue;
          dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;
          Q.push({nx, ny, nw, nt});
        }
        // 밤이면 1턴 대기
        else {
          int nt=1-t;
          if(dist[x][y][w][nt]>0)continue;
          dist[x][y][w][nt] = dist[x][y][w][t] + 1;
          Q.push({x,y,w,nt});
        }
      }
    }
  }
  cout << -1;
}