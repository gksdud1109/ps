#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    queue<pair<int,int>> Q;
    Q.push({0,0});
    
    int n = maps.size();
    int m = maps[0].size();
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        
        for(int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maps[nx][ny] == 0 || maps[nx][ny] > 1) continue;
            if(nx==0 && ny==0) continue;
            maps[nx][ny] = maps[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }
    answer = maps[n-1][m-1];
    
    if(answer == 1) return -1;
    
    return answer;
}