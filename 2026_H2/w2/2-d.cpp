/*
입력
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다. 
둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 
빈칸을 사이에 두고 차례로 주어진다. 모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 
입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

출력
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.

5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
*/

#include <bits/stdc++.h>
using namespace std;
#define X second
#define Y first

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int m, n, k;
int board[105][105];
int vis[105][105];
vector<int> size_map;

int bfs(int y, int x){
  queue<pair<int, int>> q;
  vis[y][x] = true;
  q.push({y, x});

  int area = 0;

  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    area++;

    for(int dir=0; dir<4; dir++){
      int ny = cur.Y + dy[dir];
      int nx = cur.X + dx[dir];
      if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
      if(board[ny][nx] || vis[ny][nx]) continue;

      vis[ny][nx] = true;
      q.push({ny, nx});
    }
  }

  return area;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> k;

  for(int i=0; i<k; i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for(int y=y1; y<y2; y++){
      for(int x=x1; x<x2; x++){
        board[y][x] = 1;
      }
    }
  }

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(board[i][j] || vis[i][j]) continue;

      size_map.push_back(bfs(i,j));
    }
  }

  sort(size_map.begin(), size_map.end());

  cout << size_map.size() << '\n';

  for(int area : size_map){
    cout << area << ' ';
  }

  cout << '\n';

  return 0;
}