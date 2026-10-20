#include <bits/stdc++.h>
using namespace std;
#define X second
#define Y first

int n, mx, ans;
int board[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int h){
  bool vis[105][105] = {};

  int count = 0;
  queue<pair<int, int>> q;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j] <= h || vis[i][j]) continue;

      count++;
      vis[i][j]=1;
      q.push({i, j});

      while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
          int nx=dx[dir]+cur.X;
          int ny=dy[dir]+cur.Y;

          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if(vis[ny][nx] || board[ny][nx] <= h) continue;
          q.push({ny, nx});
          vis[ny][nx]=true;
        }
      }
    }
  }

  return count;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> board[i][j];
    }
  }

  mx = board[0][0];

  for (int i = 0; i < n; i++)
      mx = max(mx, *max_element(board[i], board[i] + n));

  for(int i=0; i<=mx; i++){
    int ret = bfs(i);
    cout << i << " : " << ret << '\n';
    ans = max(ans, ret);
  }

  cout << ans << '\n';
}