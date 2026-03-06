#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, t;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<>> minHeap;

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> t;
    // 두 힙 사이즈가 같을땐 왼쪽(maxheap)그룹에 넣어서 중간값이 홀수던 짝수던 작은값을 뽑아냄
    if(maxHeap.size() <= minHeap.size()) maxHeap.push(t);
    else minHeap.push(t);
    if(!minHeap.empty() && minHeap.top() < maxHeap.top()){
      minHeap.push(maxHeap.top()); maxHeap.pop();
      maxHeap.push(minHeap.top()); minHeap.pop();
    }
    cout << maxHeap.top() << '\n';
  }
}