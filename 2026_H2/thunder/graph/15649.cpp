#include <bits/stdc++.h>
using namespace std;

int n, m;
int path[10];
bool used[10];

void func(int depth){

  if(depth == m){
    for(int i=0; i<m; i++)
      cout << path[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i=1; i<=n; i++){
    if(used[i]) continue;

    path[depth] = i;
    used[i] = true;
    func(depth+1);
    used[i] = false;
  }

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}