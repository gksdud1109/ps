#include <bits/stdc++.h>
using namespace std;
char output[2300][2300];

void printStar(int n, int x, int y){
  if(n==1){
    output[x][y] = '*';
    return;
  }
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(i==1&&j==1)
        continue;
      printStar(n/3, x+n/3*i, y+n/3*j);
    }
  }
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++)
    fill(output[i], output[i]+N, ' ');

  printStar(N, 0, 0);
  for(int i=0; i<N; i++)
    cout << output[i] << '\n';
}