#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1005][1005];
int visF[1005][1005];
int visS[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int T, W, H;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for(int testno = 0; testno < T; testno++){
    bool escape = false;
    queue<pair<int,int>> Qf = {}, Qs = {};

    cin >> W >> H;
    for(int i=0; i<H; i++){
      fill(visF[i], visF[i]+W, 0);
      fill(visS[i], visS[i]+W, 0);
    }

    for(int i=0; i<H; i++){
      for(int j=0; j<W; j++){
        char c; cin >> c;
        if(c=='#') board[i][j] = -1;
        else{
          if(c == '@'){
            Qs.push({i,j});
            visS[i][j] = 1;
          }
          else if(c == '*'){
            Qf.push({i, j});
            visF[i][j] = 1;
          }
          board[i][j] = 0;
        }
      }
    }
    while(!Qf.empty()){
      auto cur = Qf.front(); Qf.pop();
      for(int dir=0; dir<4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if(board[nx][ny]==-1) continue;
        if(visF[nx][ny]) continue;
        visF[nx][ny] = visF[cur.X][cur.Y] + 1;
        Qf.push({nx, ny});
      }
    }
    while((!Qs.empty()) && (!escape)){
      auto cur = Qs.front(); Qs.pop();
      for (int dir = 0; dir<4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= H || ny < 0 || ny >= W){
          cout << visS[cur.X][cur.Y] << '\n';
          escape = true;
          break;
        }
        if(board[nx][ny] == -1) continue;
        if(visS[nx][ny]) continue;
        if(visF[nx][ny] != 0 && visF[nx][ny] <= visS[cur.X][cur.Y]+1) continue;
        visS[nx][ny] = visS[cur.X][cur.Y] + 1;
        Qs.push({nx, ny});
      }
    }
    if(!escape) cout << "IMPOSSIBLE" << '\n';
  }
}