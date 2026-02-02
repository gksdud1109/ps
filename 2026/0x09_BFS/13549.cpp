#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
const int INF = 1e9;
int board[MX+2];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K; cin >> N >> K;
  fill(board, board+MX+1, -1);

  deque<int> DQ;
  DQ.push_back(N);
  board[N] = 0;

  while(!DQ.empty()){
    int cur = DQ.front(); DQ.pop_front();
    if(cur == K) break;

    int nx = cur*2;
    if(nx <= MX && board[nx] == -1){
      board[nx] = board[cur];
      DQ.push_front(nx);
    }

    for(int dir : {cur-1,cur+1}){
      if(dir < 0 || dir > MX) continue;
      if(board[dir] != -1) continue;
      board[dir] = board[cur]+1;
      DQ.push_back(dir);
    }
  }

  cout << board[K];
}