#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[51][51];
bool vis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int M, N, K;
queue<pair<int, int>> Q;

void bfs(int x, int y){
  vis[x][y] = true;
  Q.push({x, y});
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir=0; dir<4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(vis[nx][ny] || board[nx][ny] != 1) continue;
      vis[nx][ny] = true;
      Q.push({nx, ny});
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T; cin >> T;
  while(T--){
    cin >> M >> N >> K;
    int x, y;
    for(int i=0; i<K; i++){
      cin >> x >> y;
      board[y][x] = 1;
    }
    int res = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(board[i][j] == 1 && !vis[i][j]){
          bfs(i, j);
          res++;
        }
      }
    }
    cout << res << "\n";
    for(int i=0; i<N; i++){
      fill(board[i], board[i]+M, 0);
      fill(vis[i], vis[i]+M, false);
    }
  }
}