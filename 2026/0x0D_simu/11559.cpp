#include <bits/stdc++.h>
using namespace std;

bool isPuyo;
bool vis[12][6];
string board[12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

void resetVis() {
  for(int i = 0; i < 12; i++) {
    fill(vis[i], vis[i] + 6, false);
  }
}

void bfs(int x, int y){
  bool doErase = false;
  vis[x][y] = true;
  char color = board[x][y];
  queue<pair<int, int>> Q;
  vector<pair<int, int>> tmp;
  Q.push({x,y});
  tmp.push_back({x,y});
  while(!Q.empty()){
    pair<int,int> cur = Q.front();
    Q.pop();
    for(int dir=0; dir<4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
      if(vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue;
      vis[nx][ny] = true;
      Q.push({nx, ny}); tmp.push_back({nx, ny});
    }
  }

  if(tmp.size() >= 4){
    isPuyo = true;
    for(auto cur : tmp)
      board[cur.first][cur.second] = '.';
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0; i<12; i++)
    cin >> board[i];
  do {
    isPuyo = false;
    for(int i=0; i<6; i++){
      for(int j=10; j>=0; j--){
        int tmp = j;
        while(tmp<11 && board[tmp+1][i] == '.'){
          swap(board[tmp][i], board[tmp+1][i]);
          tmp++;
        }
      }
    }

    for(int i=0; i<12; i++)
      for(int j=0; j<6; j++)
        if(!vis[i][j] && board[i][j]!='.')
          bfs(i, j);

    if(isPuyo) ans++;
    resetVis();
  }while(isPuyo);

  cout << ans;
}