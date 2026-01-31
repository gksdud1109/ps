#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[102][102];
int vis[102][102];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int M,N,K; cin >> M >> N >> K;

  for(int i=1; i<=K; i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for(int j=y1; j<y2; j++)
      for(int k=x1; k<x2; k++)
        board[j][k] = 1;
  }

  int count=0;
  vector<int> answer;

  for(int i=0; i<M; i++){
    for(int j=0; j<N; j++){
      if(board[i][j]==1 || vis[i][j]==1)
        continue;
      
      queue<pair<int,int>> Q;
      vis[i][j] = 1;
      Q.push({i, j});
      int width = 1;
      count++;
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx<0 || nx>=M || ny<0 || ny>=N) continue;
          if(board[nx][ny]==1 || vis[nx][ny]==1) continue;
          
          Q.push({nx, ny});
          vis[nx][ny] = 1;
          width++;
        }
      }
      answer.push_back(width);
    }
  }

  sort(answer.begin(), answer.end());

  cout << count << '\n';
  for(int a : answer)
    cout << a << ' ';

  return 0;
}