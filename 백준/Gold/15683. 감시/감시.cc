#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;

int board[10][10];
int result[10][10];
vector<pair<int,int>> cctv;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void see(int curx, int cury, int dir){
  dir %= 4;
  while(1){
    curx += dx[dir];
    cury += dy[dir];
    if(curx < 0 || curx >= N || cury <0 || cury >= M || result[curx][cury]==6) return;
    if(result[curx][cury] != 0) continue;
    result[curx][cury] = 7;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  int answer=0; // 사각지대의 최소 크기

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> board[i][j];
      if(board[i][j]!=0 && board[i][j] != 6)
        cctv.push_back({i, j});
      if(board[i][j] == 0) answer++;
    }
  }
  // 1<<(2*cctv.size())는 4의 cctv.size()승을 의미, 4방향을 볼수 있는 모든 가짓수
  // 1<<N은 2의 N승 -> 1<<(2*N)은 4의 N승
  for(int tmp=0; tmp<(1<<(2*cctv.size())); tmp++){
    for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
        result[i][j] = board[i][j];
    int brute = tmp;
    for(int i=0; i<cctv.size(); i++){
      int dir=brute%4;
      brute /= 4;
      int x = cctv[i].X;
      int y = cctv[i].Y;
      if(board[x][y] == 1){
        see(x, y, dir);
      }
      else if(board[x][y] == 2){
        see(x, y, dir);
        see(x, y, dir+2);
      }
      else if(board[x][y] == 3){
        see(x, y, dir);
        see(x, y, dir+1);
      }
      else if(board[x][y] == 4){
        see(x, y, dir);
        see(x, y, dir+1);
        see(x, y, dir+2);
      }
      else{
        see(x, y, dir);
        see(x, y, dir+1);
        see(x, y, dir+2);
        see(x, y, dir+3);
      }
    }
    int val = 0;
    for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
        val += (result[i][j]==0);

    answer = min(answer, val);
  }
  cout << answer;
}