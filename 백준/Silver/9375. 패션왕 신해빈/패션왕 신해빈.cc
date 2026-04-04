#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t; cin >> t;
  while(t--){
    unordered_map<string, int> um;
    int n; cin >> n;
    string a, b;
    for(int i=0; i<n; i++){
      cin >> a >> b;
      um[b]++;
    }
    int ans = 1;
    for(auto u : um)
      ans *= u.second + 1;
    cout << ans-1 << '\n';
  }
}