#include <bits/stdc++.h>
using namespace std;

const int V = 10;
bool vis[V], adj[V][V];

void go(int u){
    vis[u] = 1;
    cout << u << '\n';

    for(int i=0; i<V; i++){
        if(vis[i]) continue;
        if(adj[u][i]){
            go(i);
        }
    }
}

int main(){
    adj[1][2] = 1; adj[2][1] = 1;
    adj[1][3] = 1; adj[3][1] = 1;
    adj[3][4] = 1; adj[4][3] = 1;


    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(adj[i][j] && vis[i] == 0){
                go(i);
            }
        }
    }
}