#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool isused[10];
int num[10];

void func(int k){
  if(k==M){
    for(int i=0; i<M; i++)
      cout << num[arr[i]] << ' ';
    cout << '\n';
    return;
  }

  int st=0;
  if(k!=0) st=arr[k-1]+1;
  for(int i=st; i<N; i++){
    arr[k] = i;
    func(k+1);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++)
    cin >> num[i];

  sort(num, num+N);
  func(0);
}