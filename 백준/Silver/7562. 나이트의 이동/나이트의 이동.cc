#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[305][305];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int T, N, X, Y, xx, yy;
queue<pair<int, int>>Q;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while(T--){
    cin >> N;
    for(int i=0; i<N; i++) fill(dist[i], dist[i]+N, -1);
    cin >> X >> Y;
    dist[X][Y] = 0;
    Q.push({X, Y});
    cin >> xx >> yy;
    while(!Q.empty()){
      auto cur = Q.front(); Q.pop();
      for(int dir=0; dir<8; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(dist[nx][ny] >=0) continue;
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        Q.push({nx, ny});
      }
    }
    cout << dist[xx][yy] << '\n';
  }
}