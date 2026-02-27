#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int K, N;
int arr[10005];

bool solve(ll x){
  ll cur = 0;
  for(int i=0; i<K; i++) cur += arr[i]/x;
  // 길이가 x일 때 랜선이 N개 이상 나올 수 있느냐
  return cur >= N;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> K >> N;
  for(int i=0; i<K; i++) cin >> arr[i];
  ll st = 1;
  ll en = 0x7fffffff;
  while(st < en){
    // mid=(st+en)/2로 두면 st와 en이 1 차이날 때 무한루프
    ll mid = (st+en+1)/2;
    if(solve(mid)) st = mid;
    else en = mid-1;
  }
  cout << st;
}