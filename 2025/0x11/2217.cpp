#include <bits/stdc++.h>
using namespace std;

int n;
int R[100005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++)  cin >> R[i];

  sort(R, R+n);
  int count=n, ans=0;

  for(int i=0; i<n; i++){
    int maxW = R[i]*count;
    if(maxW > ans) ans = maxW;
    count--;
  }

  cout << ans;
}