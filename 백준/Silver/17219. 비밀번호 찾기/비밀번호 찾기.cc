#include <bits/stdc++.h>
using namespace std;

int N, M;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  unordered_map<string, string> map;
  cin >> N >> M;
  
  string s, p;
  while(N--){
    cin >> s >> p;
    map[s] = p;
  }
  while(M--){
    cin >> s;
    cout << map[s] << '\n';
  }
}