#include <bits/stdc++.h>
using namespace std;

void parse(string& tmp, deque<int>& d){
  int cur=0;
  for(int i=1; i+1<tmp.size(); i++){
    if(tmp[i] == ','){
      d.push_back(cur);
      cur=0;
    }
    else{
      cur = 10*cur+(tmp[i]-'0');
    }
  }
  if(cur != 0) d.push_back(cur);
}

void pring_result(deque<int>& d){
  cout << '[';
  for(int i=0; i<d.size(); i++){
    cout << d[i];
    if(i+1 != d.size())
      cout << ',';
  }
  cout << "]\n";
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;

  while(T--){
    deque<int> DQ;
    int rev = 0;
    int n;
    bool isWrong = false;
    string query, tmp;
    cin >> query >> n >> tmp;

    parse(tmp, DQ);

    for(char c : query){
      if(c=='R')
        rev = 1-rev; // 0,1 토글
      else{
        if(DQ.empty()){
          isWrong=true;
          break;
        }
        if(!rev) DQ.pop_front(); // 안뒤집힌 상태에서 뽑힐 수
        else DQ.pop_back(); // 뒤집힐 상태에서 뽑힐 수
      }
    }
    if(isWrong) cout << "error\n";
    else {
      if(rev) reverse(DQ.begin(), DQ.end());
      pring_result(DQ);
    }
  }
}