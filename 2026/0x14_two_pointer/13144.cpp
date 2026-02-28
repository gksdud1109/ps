#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N; cin >> N;
  vector<int> arr(N);
  vector<bool> chk(100'002);

  for(int i=0; i<N; i++) cin >> arr[i];
  long long ans = 0;
  chk[arr[0]] = 1;
  int en=0;
  for(int st=0; st<N; st++){
    while(en<N-1 && !chk[arr[en+1]]){
      en++;
      chk[arr[en]] = 1;
    }
    ans += (en-st+1);
    chk[arr[st]] = 0;
  }
  cout << ans;
}