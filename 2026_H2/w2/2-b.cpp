#include <bits/stdc++.h>
using namespace std;
#define Y first
#define X second

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while(t--){
    int n, m, k;
    cin >> m >> n >> k; // 가로 m, 세로 n 순서로 입력

    int ans = 0;
    int board[51][51] = {};
    bool vis[51][51] = {};
    queue<pair<int,int>> q;

    for(int i=0; i<k; i++){
      int x, y; cin >> x >> y;
      board[y][x] = 1;
    }

    for(int y=0; y<n; y++){
      for(int x=0; x<m; x++){
        if(board[y][x]==0 || vis[y][x]) continue;
        ans++;
        vis[y][x] = true;
        q.push({y,x});

        while(!q.empty()){
          pair<int, int> cur = q.front(); q.pop();

          for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(board[ny][nx]==0 || vis[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push({ny, nx});
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
