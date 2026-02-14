#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[10][10]; // 현재 상태를 담는 맵
vector<pair<int,int>> cctv; // CCTV 좌표 저장
int dx[4] = {1, 0, -1, 0};  // 남, 동, 북, 서
int dy[4] = {0, 1, 0, -1};
int ans = 100; // 사각지대 최소 크기 (최댓값으로 초기화)

// 범위 체크 함수
bool OOB(int a, int b){
  return a < 0 || a >= N || b < 0 || b >= M;
}

// (x, y)에서 dir 방향으로 벽 만날 때까지 감시(#) 표시하는 함수
// 감시 영역은 7로 표시
void upd(int x, int y, int dir){
  dir %= 4;
  while(1){
    x += dx[dir];
    y += dy[dir];
    if(OOB(x,y) || board[x][y] == 6) return; // 범위를 벗어나거나 벽이면 끝
    if(board[x][y] != 0) continue; // CCTV가 있거나 이미 감시된 곳은 통과
    board[x][y] = 7; // 빈칸이면 감시 표시
  }
}

// k번째 CCTV의 방향을 정하는 함수
void dfs(int k){
  // [기저 조건] 모든 CCTV의 방향을 다 정했다면?
  if(k == cctv.size()){
    int val = 0;
    for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
        if(board[i][j] == 0) val++;
    ans = min(ans, val);
    return;
  }

  int x = cctv[k].first;
  int y = cctv[k].second;
  int type = board[x][y]; // CCTV 종류 (1~5)

  // [백트래킹 핵심] 맵 상태 백업 (되돌리기 위해)
  int tmp[10][10];
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      tmp[i][j] = board[i][j];

  // 4방향 회전 시도 (0도, 90도, 180도, 270도)
  for(int dir = 0; dir < 4; dir++){
    // 1. 맵에 감시 영역 표시 (색칠하기)
    if(type == 1){
      upd(x, y, dir);
    }
    else if(type == 2){
      upd(x, y, dir);
      upd(x, y, dir+2);
    }
    else if(type == 3){
      upd(x, y, dir);
      upd(x, y, dir+1);
    }
    else if(type == 4){
      upd(x, y, dir);
      upd(x, y, dir+1);
      upd(x, y, dir+2);
    }
    else if(type == 5){
      upd(x, y, dir);
      upd(x, y, dir+1);
      upd(x, y, dir+2);
      upd(x, y, dir+3);
    }

    // 2. 다음 CCTV로 넘어감
    dfs(k+1);

    // 3. [원상복구] 맵을 아까 백업해둔 상태로 되돌림 (백트래킹)
    for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
        board[i][j] = tmp[i][j];
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> board[i][j];
      if(board[i][j] != 0 && board[i][j] != 6)
        cctv.push_back({i, j});
    }
  }

  dfs(0); // 0번째 CCTV부터 시작
  cout << ans;
}