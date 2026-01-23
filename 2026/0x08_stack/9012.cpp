#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;

  while(T--){
    bool isVPS=true;
    string a; cin >> a; 
    stack<int> S;

    for(auto c : a){
      if (c == '(')
        S.push(c);
      else {
        if (S.empty() || S.top() != '(') {
          isVPS = false;
          break;
        }
        S.pop();
      }
    }
    if(!S.empty()) isVPS = false;

    if(isVPS) cout << "YES\n";
    else cout << "NO\n";
  }
}