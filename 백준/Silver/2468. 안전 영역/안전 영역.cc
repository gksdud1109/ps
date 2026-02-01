#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int vis[102][102];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N; cin >> N;
  int MAX=0, maxcnt=0;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> board[i][j];
      MAX = max(MAX, board[i][j]);
    }
  }
  for(int lim=0; lim <= MAX; lim++){
    for(int i=0; i<N; i++)
      fill(vis[i], vis[i]+N, 0);

    int count=0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(board[i][j] <= lim || vis[i][j]) continue;
          
        queue<pair<int,int>> Q;
        vis[i][j] = 1;
        Q.push({i, j});

        while(!Q.empty()){
          auto cur = Q.front(); Q.pop();

          for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(vis[nx][ny] || board[nx][ny] <= lim) continue;
              
            vis[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
        count++;
      }
    }
    maxcnt = max(count, maxcnt);
  }
  cout << maxcnt;
}