#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, ret;
int board[104][104];
bool vis[104][104];

void dfs(int y, int x){
    vis[y][x] = true;

    for(int dir=0; dir<4; dir++){
        int nx = x+dx[dir];
        int ny = y+dy[dir];

        if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
        if(vis[ny][nx] || board[ny][nx] == 0) continue;
        dfs(ny, nx);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 1 && !vis[i][j]){ 
                dfs(i,j);
                ret++;   
            }
        }
    }

    cout << ret << '\n';
    return 0;
}