#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int num[10];

void func(int k, int st){
  if(k==M){
    for(int i=0; i<M; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  int tmp=0;
  for(int i=st; i<N; ++i){
    if(tmp!=num[i]){
      arr[k] = num[i];
      tmp = arr[k];
      func(k+1, i+1);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++)
    cin >> num[i];

  sort(num, num+N);
  func(0, 0);
}