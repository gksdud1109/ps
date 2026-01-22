#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, L;
  cin >> N >> L;
  deque<pair<int,int>> DQ;

  for(int i=1; i<=N; i++){
    int a; cin >> a;
    
    // 새로운 숫자가 deque내에서 가장 큰 값의 숫자이고 마지막에 위치하도록,
    // deque안의 숫자들은 오름차순 정렬 유지, 구간 내 가장 작은 값은 항상 맨앞에 있는 상태가 된다.
    // 24번 줄에서 윈도우 사이즈를 벗어난건 다 제거된채로 유지되기 때문에 상기한 내용이 보장된다.
    while(!DQ.empty() && DQ.back().second >= a){
      DQ.pop_back();
    }

    DQ.push_back({i, a});

    if(DQ.front().first <= i-L){
      DQ.pop_front();
    }

    cout << DQ.front().second << ' ';
  }

  return 0;
}