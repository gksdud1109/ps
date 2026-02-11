#include <bits/stdc++.h>
using namespace std;

bool mask[25];
string board[5];
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0; i<5; i++)
    cin >> board[i];

  fill(mask+7, mask+25, true);
  do{
    queue<pair<int, int>> Q;
    // 구성원 중 이다솜파의 수, 가로세로로 인접한 사람의 수
    int dasom =0, adj=0;
    bool isp7[5][5] = {}, vis[5][5] = {};
    for(int i=0; i<25; i++){
      if(!mask[i]){
        int x=i/5, y=i%5;
        isp7[x][y] = true;
        if(Q.empty()){
          Q.push({x, y});
          vis[x][y] = true;
        }
      }
    }
    while (!Q.empty()) {
      int x, y;
      tie(x,y) = Q.front(); Q.pop();
      adj++;
      dasom += board[x][y] == 'S';
      for(int k=0; k<4; k++){
        int nx=x+dx[k], ny=y+dy[k];
        if(nx<0 || nx>=5 || ny<0 || ny>= 5 || vis[nx][ny] || !isp7[nx][ny]) continue;
        
        Q.push({nx, ny});
        vis[nx][ny] =true;
      }
    }
    ans += (adj >= 7 && dasom>=4);
  }while(next_permutation(mask, mask+25));
  cout << ans;
}