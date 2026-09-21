#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[1000005], b, c, psum[1000005], n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i=1; i<=n; i++){
    cin >> arr[i];
    psum[i] = psum[i-1] + arr[i];
  }

  for(int i=0; i<m; i++){
    cin >> b >> c;
    cout << psum[c] - psum[b-1] << "\n";
  }
  return 0;

}