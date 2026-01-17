#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  stack<int> S;

  while(N--){
    string comm;
    cin >> comm;
    if(comm == "push"){
      int num;
      cin >> num;
      S.push(num);
    }
    else if(comm == "pop"){
      if(S.empty()) cout << -1 << '\n';
      else{
        int num = S.top();
        S.pop();
        cout << num << '\n';
      }
    }
    else if(comm == "top"){
      if(S.empty()) cout << -1 << '\n';
      else cout << S.top() << '\n';
    }
    else if(comm == "empty"){
      cout << (int)S.empty() << '\n';
    }
    else if(comm == "size"){
      cout << S.size() << '\n';
    }

  }
}