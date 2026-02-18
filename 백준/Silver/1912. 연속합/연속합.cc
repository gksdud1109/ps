#include <bits/stdc++.h>
using namespace std;

int N;
int a[100005];
int D[100005]; // D[i] = i번째 항으로 끝나는 연속합 중 최댓값

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=1; i<=N; i++)
    cin >> a[i];

  for(int i=1; i<=N; i++)
    D[i] = max(0, D[i-1]) + a[i]; // 연속을 끊을지, 새로갈지

  cout << *max_element(D+1, D+N+1);
}