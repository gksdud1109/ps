#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, year;
int area[303][303];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void melting(){
  int zero[303][303] = {0};
  // 테두리는 항상 0이므로 1~n-1까지만 탐색
  for(int i=1; i<N-1; i++){
    for(int j=1; j<M-1; j++){
      if(area[i][j] == 0) continue;
      for(int dir=0; dir<4; dir++){
        if(area[i+dx[dir]][j+dy[dir]] == 0) zero[i][j]++;
      }
    }
  }
  for(int i=1; i<N-1; i++){
    for(int j=1; j<M-1; j++){
      area[i][j] = max(0, area[i][j] - zero[i][j]);
    }
  }
}

int status(){
  int x=-1, y=-1, cnt1=0, cnt2=0;
  bool vis[303][303] = {false};

  for(int i=1; i<N-1; i++){
    for(int j=1; j<M-1; j++){
      if(area[i][j] > 0){
        x=i; y=j;
        cnt1++;
      }
    }
  }

  if(cnt1==0) return 0;

  queue<pair<int, int>> Q;
  Q.push({x, y});
  vis[x][y] = true;

  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    cnt2++;
    for(int i=0; i<4; i++){
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if(!vis[nx][ny] && area[nx][ny] >0){
        vis[nx][ny] = true;
        Q.push({nx, ny});
      }
    }
  }

  if(cnt1 == cnt2) return 1; // 한 덩이
  return 2; // 분리됨
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++) cin >> area[i][j];
  }

  int year=0;
  while(true){
    int check = status();
    if(check == 0){
      cout << 0;
      return 0;
    } else if(check == 2){
      cout << year;
      return 0;
    }

    year++;
    melting();
  }
}