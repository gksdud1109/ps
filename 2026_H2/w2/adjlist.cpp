#include <bits/stdc++.h>
using namespace std;

const int V = 10;
vector<int> adj[V];
int vis[V];

void go(int u){
    vis[u] = 1;
    cout << u << '\n';

    for(int v : adj[u]){
        if(vis[v]) continue;
        go(v);
    }
}

int main(){

    adj[1].push_back(2);
    adj[2].push_back(1);
    
    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    for(int i=0; i<V; i++){
        if(adj[i].size() && vis[i]==0) go(i);
    }
}