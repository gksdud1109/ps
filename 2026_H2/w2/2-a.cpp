#include <bits/stdc++.h>
using namespace std;
#define Y first
#define X second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m; // n이 세로, m이 가로로 주어짐
int board[105][105];
int dist[105][105];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  queue<pair<int,int>> q;

  for(int i=0; i<n; i++){
    string row;
    cin >> row;
    for(int j=0; j<m; j++){
      board[i][j] = row[j] - '0';
    }
  }

  q.push({0, 0});
  dist[0][0] = 1;
  while(!q.empty()){
    pair<int, int> cur = q.front(); q.pop();

    for(int dir=0; dir<4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      if(dist[ny][nx] > 0 || board[ny][nx]==0) continue;
      dist[ny][nx] = dist[cur.Y][cur.X] + 1;
      q.push({ny, nx});
    }
  }

  cout << dist[n-1][m-1] << '\n';
  return 0;
}
