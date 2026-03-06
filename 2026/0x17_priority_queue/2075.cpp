#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, num;
  priority_queue<int, vector<int>, greater<>> pq;
  cin >> N;

  for(int i=0; i<N*N; i++){
    cin >> num;
    pq.push(num);
    if(N<(int)pq.size()) pq.pop();
  }

  cout << pq.top() << '\n';
}