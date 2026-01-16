#include <bits/stdc++.h>
using namespace std;

int N, K, len = 0;

int pre[5001];
int nxt[5001];
vector<int> vec;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  // 원형 연결리스트, 맨 처음과 마지막 노드는 서로를 가리킴
  for(int i=1; i<= N; i++){
    pre[i] = (i==1) ? N : i-1;
    nxt[i] = (i==N) ? 1 : i+1;
    len++;
  }

  int i=1;
  for(int cur=1; len!=0; cur=nxt[cur]){
    if(i==K){
      pre[nxt[cur]] = pre[cur]; // 다음 노드의 pre[]를 현재 노드의 pre[]값으로 연결
      nxt[pre[cur]] = nxt[cur]; // 이전 노드의 nxt[]를 현재 노드의 nxt[]값으로 연결
      // A <-> B <-> C  노드 연결에서 B가 빠지고 A와 C를 연결해줌

      vec.push_back(cur);
      i=1;
      len--;
    }
    else
      i++;
  }

  cout << "<";
  for(size_t i = 0; i < vec.size(); i++){
    cout << vec[i];
    if(i != vec.size()-1) cout << ", ";
  }
  cout << ">";

}