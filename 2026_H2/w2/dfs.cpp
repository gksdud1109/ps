#include <bits/stdc++.h>
using namespace std;
const int n = 10;

vector<int> adj[n];
bool vis[n];

void dfs(int u){
    vis[u] = true;
    cout << u << '\n';
    for(int v: adj[u]){
        if(vis[v]==0) dfs(v);
    }
    cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(4); adj[4].push_back(2);
    adj[2].push_back(5); adj[5].push_back(2);
    adj[1].push_back(3); adj[3].push_back(1);

    dfs(1);
}