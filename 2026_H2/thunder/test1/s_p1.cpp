#include <bits/stdc++.h>
using namespace std;

int n, m;
int coupon[100000], price[100000];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) cin >> price[i];

  cin >> m;
  for(int i=0; i<m; i++) cin >> coupon[i];

  sort(price, price+n, greater<int>());
  sort(coupon, coupon+m, greater<int>());

  long long sum = 0;
  int cur = 0;
  while(cur < m && cur < n) {
    sum += floor(price[cur]*(100-coupon[cur])/100);
    cur++;
  }

  while(cur < n) sum += price[cur++];

  cout << sum;

}