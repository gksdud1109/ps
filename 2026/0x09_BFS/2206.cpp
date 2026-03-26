#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[1005][1005];
int dist[1005][1005][2];
int N, M;

int bfs(){
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      dist[i][j][0] = dist[i][j][1] = -1;
  dist[0][0][1] = dist[0][0][1] = 1;
  queue<tuple<int,int,int>> Q;
  Q.push({0,0,0});
  while(!Q.empty()){
    int x, y, broken;
    tie(x, y, broken) = Q.front(); Q.pop();
    if(x == N-1 && y==M-1) return dist[x][y][broken];
    int nextdist = dist[x][y][broken] + 1;
    for(int dir=0; dir<4; dir++){
      int nx = x+dx[dir];
      int ny = y+dy[dir];
      if(nx < 0 || nx>=N || ny<0 || ny>= M) continue;
      if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1){
        dist[nx][ny][broken] = nextdist;
        Q.push({nx, ny, broken});
      }
      if(!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1){
        dist[nx][ny][1] = nextdist;
        Q.push({nx,ny,1});
      }
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> board[i][j];
    }
  }
  cout << bfs();
  return 0;
}