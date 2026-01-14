#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> pokimon;
string index_of_pokimon[100005];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  for(int i=1; i<=n; i++){
    cin >> index_of_pokimon[i];
    pokimon[index_of_pokimon[i]] = i;
  }

  for(int i=1; i<=m; i++){
    string cmd;
    cin >> cmd;
    if(isdigit(cmd[0]))
      cout << index_of_pokimon[stoi(cmd)] << '\n';
    else
      cout << pokimon[cmd] << '\n';
  }
}