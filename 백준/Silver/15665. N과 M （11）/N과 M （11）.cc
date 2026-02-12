#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int num[10];

void func(int k){
  if(k==M){
    for(int i=0; i<M; i++)
      cout << num[arr[i]] << ' ';
    cout << '\n';
    return;
  }

  int tmp=0;
  for(int i=0; i<N; ++i){
    arr[k] = i;
    func(k+1);
  }
}

vector<bool> chk(10002);

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  int idx=0;
  // 카드 무제한 중복사용 가능, 어차피 무한리필이면 같은 수가 중복존재할 필요 없음
  while(N--){
    cin >> num[idx];
    if(chk[num[idx]]) continue;
    chk[num[idx]] = true;
    idx++;
  }

  N = idx;
  sort(num, num+N);
  func(0);
}