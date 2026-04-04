#include <bits/stdc++.h>
using namespace std;

int ttoi(string s){
  int h = stoi(s.substr(0,2));
  int m = stoi(s.substr(3,2));

  return h*60 + m;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string S, E, Q;
  cin >> S >> E >> Q;

  int st_t=ttoi(S), end_t=ttoi(E), quit_t=ttoi(Q);

  unordered_set<string> st_list;
  unordered_set<string> atd_list;

  while(true){
    string c_time, name;
    cin >> c_time >> name;
    if(cin.eof() == true) break;

    if(ttoi(c_time) <= st_t)
      st_list.insert(name);
    else if(ttoi(c_time) >= end_t && ttoi(c_time) <= quit_t){
      if(st_list.find(name) != st_list.end()){
        atd_list.insert(name);
      }
    }
  }

  cout << atd_list.size() << "\n";
  return 0;
}