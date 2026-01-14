#include <bits/stdc++.h>
using namespace std;
int N;
int inputVid[64][64];
string outputVid = "";

bool check(int x, int y, int size){
  for(int i=x; i<x+size; i++)
    for(int j=y; j<y+size; j++)
      if(inputVid[x][y] != inputVid[i][j])
        return false;
  return true;
}
void compress(int x, int y, int size){
  if(check(x, y, size)){
    outputVid += ('0' + inputVid[x][y]);
    return;
  }
  int half = size / 2;
  outputVid += '(';
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      compress(x+i*half, y+j*half, half);
    }
  }
  outputVid += ')';
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < N; j++)
      inputVid[i][j] = str[j] - '0';
  }

  compress(0, 0, N);
  cout << outputVid;
}