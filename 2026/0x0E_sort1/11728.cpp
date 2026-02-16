#include <bits/stdc++.h>
using namespace std;

int A[1000005];
int B[1000005];
int C[2000005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i=0; i<N; i++)
    cin >> A[i];

  for(int j=0; j<M; j++)
    cin >> B[j];
  
  int aidx=0, bidx=0;

  for(int i=0; i<N+M; i++){
    if(bidx==M) C[i] = A[aidx++];
    else if(aidx==N) C[i] = B[bidx++];
    else if(A[aidx] <= B[bidx]) C[i] = A[aidx++];
    else C[i] = B[bidx++];
  }

  for(int i=0; i<N+M; i++) 
    cout << C[i] << ' ';
}