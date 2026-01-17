#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  stack<int> S;
  int count = 1;
  string ans;

  while(n--){
    int cur;
    cin >> cur;
    while(count <= cur){
      S.push(count++);
      ans += "+\n";
    }
    if(S.top() != cur){ 
      // 맨 위에 cur이 있어야 pop을 할수 있음,
      // 21534처럼 543순으로 쌓여있는데 3을 먼저 꺼내야 하는경우 해당
      cout << "NO\n";
      return 0;
    }
    S.pop();
    ans += "-\n";
  }

  cout << ans;
}