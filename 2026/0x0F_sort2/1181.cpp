#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  vector<string> v(N);

  for(int i=0; i<N; i++)
    cin >> v[i];
  sort(v.begin(), v.end(), [](const string& a, const string& b){
    int al = a.length();
    int bl = b.length();
    if(al != bl) return al  < bl;
    return a < b;
  });
  v.erase(unique(v.begin(), v.end()), v.end()); // 중복된 원소 제거
  for(string& s : v) cout << s << '\n';
}