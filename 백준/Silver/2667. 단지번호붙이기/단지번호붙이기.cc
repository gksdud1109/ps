#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[25];
int vis[25][25];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N; cin >> N;
  for(int i=0; i<N; i++){
    cin >> board[i];
  }

  int count=0;
  vector<int> answer;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(board[i][j]=='0' || vis[i][j]==1) continue;

      queue<pair<int,int>> Q;
      vis[i][j] =1;
      Q.push({i, j});
      int width =1;
      count++;
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(nx<0 || nx>= N || ny<0 || ny>=N) continue;
          if(board[nx][ny]=='0' || vis[nx][ny]==1) continue;

          Q.push({nx, ny});
          vis[nx][ny] =1;
          width++;
        }
      }
      answer.push_back(width);
    }
  }
  cout << count << '\n';
  sort(answer.begin(), answer.end());

  for(auto a : answer)
    cout << a << '\n';

  return 0;
}