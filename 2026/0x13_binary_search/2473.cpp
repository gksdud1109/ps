#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
ll arr[5005];
ll ans[3] = {0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for(int i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N);

  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      int idx = lower_bound(arr, arr+N, -arr[i]-arr[j]) - arr;

      for(int k=-3; k<=2; k++){
        if(idx+k == i || idx+k == j) continue;
        if(idx+k < 0 || idx+k >= N) continue;
        if(abs(ans[0] + ans[1] + ans[2]) > abs(arr[i] + arr[j] + arr[idx+k]))
          tie(ans[0], ans[1], ans[2]) = {arr[i], arr[j], arr[idx+k]};
      }
    }
  }
  sort(ans, ans+3);
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
  // 투포인터를 쓰는 것이 더 안전하고 직관적인 문제
}