#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int I;
    cin >> I;
    int board[301][301];
    int dist[301][301];

    queue<pair<int, int>> Q;

    int curX, curY, destX, destY;
    cin >> curX >> curY >> destX >> destY;

    for (int i = 0; i < I; i++)
      fill(dist[i], dist[i] + I, -1);

    board[curX][curY] = 1;

    Q.push({curX, curY});
    dist[curX][curY] = 0;
    while (!Q.empty())
    {
      auto cur = Q.front();
      Q.pop();
      for (int dir = 0; dir < 8; dir++)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= I || ny < 0 || ny >= I)
          continue;
        if (dist[nx][ny] != -1)
          continue;
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        Q.push({nx, ny});
      }
    }
    cout << dist[destX][destY] << '\n';
  }
}