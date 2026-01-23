#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll ans = 0;
stack<char> st;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  int sz = s.length();
  for(int i=0; i<sz; i++){
    if(s[i]=='(')
      st.push(s[i]);
    else {
      if(s[i-1] == '('){ // ()인, 레이저의 케이스
        st.pop(); // 레이저이므로 막대에서는 빼야함
        ans += st.size(); // 지금 레이저에서 잘린 막대의 개수
      }
      else { // ))인, 막대의 끝인 케이스
        st.pop(); // 막대의 개수를 감소
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}