#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> DQ;

  int N, M, answer = 0;
  cin >> N >> M;

  for(int i=1; i<=N; i++)
    DQ.push_back(i);

  while(M--){
    int cur; cin >> cur;

    int idx = 0;
    for(int a : DQ){
      if(a==cur) break;
      idx++;
    }
    if(idx <= (int)(DQ.size()/2)){
      while(DQ.front() != cur) {
        DQ.push_back(DQ.front());
        DQ.pop_front();
        answer++;
      }
    }
    else{
      while(DQ.front() != cur) {
        DQ.push_front(DQ.back());
        DQ.pop_back();
        answer++;
      }
    }

    DQ.pop_front();
  }

  cout << answer;
}