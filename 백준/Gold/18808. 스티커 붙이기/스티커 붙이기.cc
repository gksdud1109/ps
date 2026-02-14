#include <bits/stdc++.h>
using namespace std;

int board[42][42];
int paper[12][12];
int N, M, K;
int R, C;

void rotate(){
  int tmp[12][12];
  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++)
      tmp[i][j] = paper[i][j];
  
  for(int i=0; i<C; i++)
    for(int j=0; j<R; j++)
      paper[i][j] = tmp [R-1-j][i];
  
  swap(R, C);
}

bool pastable(int x, int y){
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(board[x+i][y+j]==1 && paper[i][j]==1)
        return false;
    }
  }

  // 붙일 수 있으면 붙이고 반환
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(paper[i][j] == 1)
        board[x+i][y+j] = 1;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;

  while(K--){
    cin >> R >> C;
    for(int i=0; i<R; i++)
      for(int j=0; j<C; j++)
        cin >> paper[i][j];

    for(int rot=0; rot<4; rot++){
      bool is_paste = false;
      for(int x=0; x<= N-R; x++){
        if(is_paste) break;
        for(int y=0; y<= M-C; y++){
          if(pastable(x, y)){
            is_paste = true;
            break;
          }
        }
      }

      if(is_paste) break;
      rotate();
    }
  }

  int cnt = 0;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      cnt += board[i][j];
  cout << cnt << '\n';
}