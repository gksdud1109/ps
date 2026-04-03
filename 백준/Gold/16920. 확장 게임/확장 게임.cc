#include <bits/stdc++.h>
using namespace std;
#define first X
#define second Y

int n, m, p;
char board[1005][1005];
int step[10], area[10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int,int>> Q[10];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> p;
  for(int i=1; i <= p; i++) cin >> step[i];

  for(int i=0; i<n; i++){
    cin >> board[i];
    for(int j=0; j<m; j++){
      if(isdigit(board[i][j])){
        int player = board[i][j] - '0';
        Q[player].push({i, j});
        area[player]++;
      }
    }
  }

  while(true){
    bool isExtend = false;

    for(int i=1; i<=p; i++){
      int moves = step[i];

      while(moves-- && !Q[i].empty()){
        int qSize = Q[i].size();
        while(qSize--){
          auto[curx, cury] = Q[i].front();
          Q[i].pop();
          for(int dir=0; dir<4; dir++){
            int nx = curx + dx[dir];
            int ny = cury + dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(board[nx][ny] == '.'){
              board[nx][ny] = i+'0';
              area[i]++;
              Q[i].push({nx, ny});
              isExtend = true;
            }
          }
        }
      }
    }
    if(!isExtend) break;
  }

  for(int i=1; i<=p; i++) cout << area[i] << " ";
}