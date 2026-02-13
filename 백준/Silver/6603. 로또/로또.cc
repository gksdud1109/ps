#include <bits/stdc++.h>
using namespace std;

int K, input[20], arr[10];

void func(int k, int st){
  if(k == 6){
    for(int i=0; i<6; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i=st; i<K; i++){
    arr[k] = input[i];
    func(k+1, i+1);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    cin >> K;
    if(K==0) break;
    for(int i=0; i<K; i++)
      cin >> input[i];
    func(0,0);
    cout << '\n';
  }
}