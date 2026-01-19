#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  queue<int> Q;

  while(N--){
    string comm;
    cin >> comm;

    if(comm == "push"){
      int x;
      cin >> x;
      Q.push(x);
    }
    else if(comm == "pop"){
      if(Q.empty()) cout << -1 << '\n';
      else {
        cout << Q.front() << '\n';
        Q.pop();
      }
    }
    else if(comm == "size"){
      cout << Q.size() << '\n';
    }
    else if(comm == "empty"){
      cout << Q.empty() << '\n';
    }
    else if(comm == "front"){
      if(Q.empty()) cout << -1 << '\n';
      else cout << Q.front() << '\n';
    }
    else if(comm == "back"){
      if(Q.empty()) cout << -1 << '\n';
      else cout << Q.back() << '\n';
    }
  }
}