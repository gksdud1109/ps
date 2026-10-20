#include <bits/stdc++.h>
using namespace std;

int n;
string board[64];

void solve(int y, int x, int size){
  char first = board[y][x];
  bool same = true;

  for(int i=y; i<y+size; i++){
    for(int j=x; j<x+size; j++){
      if(board[i][j] != first){
        same = false;
      }
    }
  }

  if(same){
    cout << first;
    return;
  }

  int half = size/2;
  cout << '(';

  solve(y, x, half);
  solve(y, x+half, half);
  solve(y+half, x, half);
  solve(y+half, x+half, half);

  cout << ')';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i=0; i<n; i++){
    cin >> board[i];
  }

  solve(0,0,n);
  cout << '\n';

  return 0;
}