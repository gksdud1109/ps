#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
int N, M, R;

void op1(){
  for(int i=0; i<N/2; i++){
    swap(arr[i], arr[N-i-1]);
  }
}

void op2(){
  for(int i=0; i<N; i++){
    for(int j=0; j<M/2; j++)
      swap(arr[i][j], arr[i][M-1-j]);
  }
}

void op3(){
  vector<vector<int>> tmp(M, vector<int>(N));
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      tmp[j][N-1-i] = arr[i][j];
  arr = tmp;
  swap(N,M);
}

void op4(){
  vector<vector<int>> tmp(M, vector<int>(N));
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      tmp[M-1-j][i] = arr[i][j];

  arr = tmp;
  swap(N,M);
}

void op5(){
  vector<vector<int>> tmp(N, vector<int>(M));

  int n_mid = N/2;
  int m_mid = M/2;

  for(int i=0; i<n_mid; i++){
    for(int j=0; j<m_mid; j++){
      tmp[i][j+m_mid] = arr[i][j];
      tmp[i+n_mid][j+m_mid] = arr[i][j+m_mid];
      tmp[i+n_mid][j] = arr[i+n_mid][j+m_mid];
      tmp[i][j] = arr[i+n_mid][j];
    }
  }

  arr = tmp;
}

void op6() {
    vector<vector<int>> temp(N, vector<int>(M));
    int n_mid = N / 2;
    int m_mid = M / 2;

    for (int i = 0; i < n_mid; i++) {
        for (int j = 0; j < m_mid; j++) {
            temp[i + n_mid][j] = arr[i][j];
            temp[i + n_mid][j + m_mid] = arr[i + n_mid][j];
            temp[i][j + m_mid] = arr[i + n_mid][j + m_mid];
            temp[i][j] = arr[i][j + m_mid];
        }
    }
    arr = temp;
}



int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> R;
  arr.assign(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  while(R--){
    int comm; cin >> comm;
    if(comm == 1) op1();
    else if(comm == 2) op2();
    else if(comm == 3) op3();
    else if(comm == 4) op4();
    else if(comm == 5) op5();
    else if(comm == 6) op6();
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
    
  return 0;
}