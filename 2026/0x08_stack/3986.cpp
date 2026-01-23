#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N; cin >> N;
  int answer = 0;

  while(N--){
    string a; cin >> a;

    stack<int> S;
    for(auto c : a){
      if(!S.empty() && S.top() == c) S.pop();
      else S.push(c);
    }
    if(S.empty()) answer++;
  }
  cout << answer << '\n';
}