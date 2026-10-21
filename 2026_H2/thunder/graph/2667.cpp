#include <bits/stdc++.h>
using namespace std;
#define X second
#define Y first

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n;
string board[26];
bool vis[26][26];

int bfs(int y, int x){
  queue<pair<int,int>> q;

  vis[y][x] = true;
  q.push({y, x});

  int width = 0;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    int curY = cur.Y;
    int curX = cur.X;

    width++;

    for(int dir=0; dir<4; dir++){
      int ny = curY + dy[dir];
      int nx = curX + dx[dir];
      if(ny < 0 || ny >= n || nx <0 || nx >=n ) continue;
      if(board[ny][nx]=='0' || vis[ny][nx]) continue;
      vis[ny][nx] = true;
      q.push({ny, nx});
    }
  }

  return width;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++) cin >> board[i];
    
    vector<int> answer;

    for(int y=0; y<n; y++){
      for(int x=0; x<n; x++){
        if(board[y][x]=='0' || vis[y][x]) continue;

        answer.push_back(bfs(y,x));
      }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for (int area : answer) {
      cout << area << '\n';
    }

    return 0;
}
