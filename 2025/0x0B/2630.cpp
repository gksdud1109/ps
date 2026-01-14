#include <bits/stdc++.h>
using namespace std;
int N;
int paper[128][128];
int cntW=0, cntB=0;
bool check(int x, int y, int size){
  for(int i=x; i<x+size; i++)
    for(int j=y; j<y+size; j++)
      if(paper[x][y] != paper[i][j]){
        return false;
      }
  return true;
}

void solve(int x, int y, int size){
  if(check(x,y,size)){
    if(paper[x][y]==0)
      cntW++;
    else
      cntB++;
    return;
  }
  int half = size/2;
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
      solve(x+i*half, y+j*half, half);
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin >> paper[i][j];

  solve(0,0,N);

  cout << cntW << '\n' << cntB;
}