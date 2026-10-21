#include<bits/stdc++.h>
using namespace std;

int huddle[21][2];
int h, w, k;
int answer=0;

int dfs(int x, int y){
  if(y<=0 || y>=h) return 0;
  if(huddle[x][0] != 0 && (y<=huddle[x][0] || y>=huddle[x][1])) return 0;
  if(x == w) return 1;

  return dfs(x+1, y+1) + dfs(x+1, y-2);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> h >> w >> k;
  for(int i=0; i<k; i++){
    int x; cin >> x;
    cin >> huddle[x][0];
    cin >> huddle[x][1];
  }

  int st = h/2;

  cout << dfs(0, st);
}