#include <bits/stdc++.h>
using namespace std;

const int MX = 31;
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int l, r, c;
  while(cin >> l >> r >> c, l || r || c){
    char board[MX][MX][MX];
    int dist[MX][MX][MX];

    for(int z=0; z<l; z++){
      for(int x=0; x<r; x++){
        fill(dist[z][x], dist[z][x]+c, -1);
      }
    }

    queue<tuple<int, int, int>> Q;
    tuple<int,int,int> start;

    for(int z=0; z<l; z++){
      for(int x=0; x<r; x++){
        for(int y=0; y<c; y++){
          cin >> board[z][x][y];
          if(board[z][x][y] == 'S'){
            start = {z, x, y};
          }
        }
      }
    }

    auto [sz, sx, sy] = start;
    dist[sz][sx][sy] = 0;
    Q.push(start);

    int escape = -1;

    while(!Q.empty()){
      auto [z, x, y] = Q.front(); Q.pop();

      if(board[z][x][y] == 'E'){
        escape = dist[z][x][y];
        break; // BFS니까 최초 도달한게 최단거리
      }

      for(int dir=0; dir<6; dir++){
        int nz= z + dz[dir], nx= x + dx[dir], ny= y+dy[dir];
        if(nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(board[nz][nx][ny] == '#') continue;
        if(dist[nz][nx][ny] != -1) continue;

        dist[nz][nx][ny] = dist[z][x][y] + 1;
        Q.push({nz, nx, ny});
      }
    }

    if(escape != -1) cout << "Escaped in " << escape << " minute(s).\n";
    else cout << "Trapped!\n";
  }
}