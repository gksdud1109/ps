#include <bits/stdc++.h>
using namespace std;

int main(){
  string s = "hello";
  s += " BKD!";

  cout << s.size() << '\n';
  cout << s.substr(2, 3) << '\n';
  cout << s[1] << '\n';
  s.replace(6, 4, "guys");
  cout << s << '\n';
  int it = s.find("guys");
  s.replace(it, 4, "everyone");
  cout << s << '\n';
  s.erase(7, 6);
  cout << s << '\n';
  s[6] = 'm';
  cout << s << '\n';
  s.insert(0, "say ");
  cout << s << '\n';
  if(s.find("to") == string::npos)
    cout << "'to' is not in string 's'\n";
}