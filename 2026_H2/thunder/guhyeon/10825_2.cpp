#include <bits/stdc++.h>
using namespace std;

struct A{ string name; int k, e, m; };
bool cmp(A a, A b){
  if(a.k != b.k) return a.k > b.k;
  if(a.e != b.e) return a.e < b.e;
  if(a.m != b.m) return a.m > b.m;
  return a.name < b.name;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<A> v(n);

  for(auto& i : v) cin >> i.name >> i.k >> i.e >> i.m;
  sort(v.begin(), v.end(), cmp);
  for(auto i : v) cout << i.name << '\n';
  return 0;
}