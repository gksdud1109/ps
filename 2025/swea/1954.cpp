#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void){
  int test_case;
	int T;
  cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int n;
    cin >> n;

    int board[10][10] = {0};
    int x = 0, y = 0, dir = 0;
    for(int count = 1; count <= n * n; count++){
      board[x][y] = count;
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] != 0){
        dir = (dir + 1) % 4;
        nx = x + dx[dir];
        ny = y + dy[dir];
      }
      x = nx;
      y = ny;
    }
    cout << '#' << test_case << '\n';
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        cout << board[i][j] << ' ';
      cout << '\n';
    }
	}
	return 0;
}