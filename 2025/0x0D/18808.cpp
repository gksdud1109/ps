#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[40][40];
vector<vector<vector<int>>> sticker;
int n, m, k;

vector<vector<int>> rotate90(const vector<vector<int>>& mat) {
  int R = mat.size(), C = mat[0].size();
  vector<vector<int>> rotated(C, vector<int>(R));
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      rotated[j][R - i - 1] = mat[i][j];
  return rotated;
}

int main(void){
  cin >> n >> m >> k;
  for(int ki=0; ki<k; ki++){
    int r, c;
    cin >> r >> c;

    vector<vector<int>> one(r, vector<int>(c));
    for(int i=0; i<r; i++)
      for (int j = 0; j < c; j++)
        cin >> one[i][j];
    sticker.push_back(one);
  }
  
  for(int i=0; i<k; i++){
    sticker[i];
  }
  
}