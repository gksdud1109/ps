#include <bits/stdc++.h>
using namespace std;

int board[202][202];
int vis[32][202][202];
int dmx[4] = {0,0,1,-1};
int dmy[4] = {1,-1,0,0};
int dkx[8] = {-2,-2,-1,-1,1,1,2,2};
int dky[8] = {1,-1,2,-2,2,-2,1,-1};
queue<tuple<int,int,int>> Q;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int bX, bY, K; cin >> K >> bY >> bX;
  for(int i=0; i<bX; i++)
    for(int j=0; j<bY; j++)
      cin >> board[i][j];
  
  Q.push({0,0,0});
  vis[0][0][0] = 1;
  while(!Q.empty()){
    int curk, curx, cury;
    tie(curk, curx, cury) = Q.front(); Q.pop();
    if(curk < K){
      for(int i=0; i<8; i++){
        int nx = curx + dkx[i], ny = cury + dky[i];
        if(nx<0 || ny<0 || nx>=bX || ny>=bY) continue;
        if(board[nx][ny]) continue;
        if(vis[curk+1][nx][ny]) continue;
        vis[curk+1][nx][ny] = vis[curk][curx][cury] +1;
        Q.push({curk+1, nx, ny});
      }
    }
    for(int i=0; i<4; i++){
      int nx=curx+dmx[i], ny=cury+dmy[i];
      if(nx<0 || ny<0 || nx>=bX || ny>=bY) continue;
      if(board[nx][ny] || vis[curk][nx][ny]) continue;
      vis[curk][nx][ny] = vis[curk][curx][cury]+1;
      Q.push({curk, nx, ny});
    }
  }

  int answer = 0x7f7f7f7f;
  for(int i=0; i<=K; i++)
    if(vis[i][bX-1][bY-1]) answer = min(answer, vis[i][bX-1][bY-1]);
  if(answer != 0x7f7f7f7f) cout << answer-1;
  else cout << -1;
}