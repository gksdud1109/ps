#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  deque<int> DQ;
  
  int N; cin >> N;

  while(N--){
    string comm; cin >> comm;

    if(comm == "push_front"){
      int x; cin >> x;
      DQ.push_front(x);
    }
    else if(comm == "push_back"){
      int x; cin >> x;
      DQ.push_back(x);
    }
    else if(comm == "pop_front"){
      if(DQ.empty()) cout << -1 << '\n';
      else {
        cout << DQ.front() << '\n';
        DQ.pop_front();
      }
    }
    else if(comm == "pop_back"){
      if(DQ.empty()) cout << -1 << '\n';
      else {
        cout << DQ.back() << '\n';
        DQ.pop_back();
      }
    }
    else if(comm == "size"){
      cout << DQ.size() << '\n';
    }
    else if(comm == "empty"){
      cout << DQ.empty() << '\n';
    }
    else if(comm == "front"){
      if(DQ.empty()) cout << -1 << '\n';
      else cout << DQ.front() << '\n';
    }
    else if(comm == "back"){
      if(DQ.empty()) cout << -1 << '\n';
      else cout << DQ.back() << '\n';
    }
  }

}