#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> vis(n, false);
    
    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        answer++;
        
        queue<int> Q;
        Q.push(i);
        vis[i] = true;
        
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(int nxt=0; nxt<n; nxt++){
                if(computers[cur][nxt] == 1 && !vis[nxt]){
                    vis[nxt] = true;
                    Q.push(nxt);
                }
            }
        }
    }
    
    return answer;
}