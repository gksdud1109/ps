#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
stack<pair<int, int>> tower;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  tower.push({100000001, 0}); // 첫 왼쪽 타워를 위한 처리

  for(int i=1; i<=N; i++){
    int height;
    cin >> height;
    // 현재 타워보다 낮은 타워들은
    // - 현재 타워의 신호 받을 수 없음
    // - 다음 올 타워들의 신호도 받을 수 없음 -> 제거
    while(tower.top().X < height)
      tower.pop();
    
    // 현 타워의 신호를 수신할 타워 인덱스
    cout << tower.top().Y << " ";
    
    // push해서 다음 값과 비교할 준비
    tower.push({height, i});
  }
}