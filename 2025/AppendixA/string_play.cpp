#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& s, const string& sep){
  vector<string> ret;
  int pos=0;
  while(pos < s.size()){
    int nxt_pos = s.find(sep, pos);
    if(nxt_pos==-1) nxt_pos=s.size();
    if(nxt_pos-pos > 0)
      ret.push_back(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + sep.size();
  }
  return ret;
}

int main(){
  string s="hello";
  s += " BKD!";
  cout << s.size() << '\n';
  cout << s.substr(2,3) << '\n';
  cout << s[1] << '\n';
  s.replace(6,4,"guys");
  cout << s << '\n';
  int it = s.find("guys");
  s.replace(it,3,"everyone");
  cout << s << '\n';
  s.erase(7,6);
  cout << s << '\n';
  s[6] = 'm';
  cout << s << '\n';
  if(s.find("to") == string::npos)  // string::npos == -1
    cout << "'to' is not in string 's' \n";
  
  vector<string> chunks1 = split("welcome to the black parade", " ");
  for(auto chunk:chunks1) cout << chunk << '/';
  cout << '\n';
  vector<string> chunks2 = split("b*!*ac*!**!*e*!*y*!*", "*!*");
  for(auto chunk:chunks2) cout << chunk << '/';
}