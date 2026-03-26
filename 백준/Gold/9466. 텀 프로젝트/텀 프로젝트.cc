#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int N;
int state[100005];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x){
  int cur = x;
  while(true){
    state[cur] = x;
    cur = arr[cur];
    if(state[cur] == x){
      while(state[cur] != CYCLE_IN){
        state[cur] = CYCLE_IN;
        cur = arr[cur];
      }
      return;
    }
    else if(state[cur] != 0) return;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  while(T--){
    cin >> N;
    fill(state+1, state+N+1, 0);
    for(int i=1; i<=N; i++)
      cin >> arr[i];
    int ans = 0;
    for(int i= 1; i<=N; i++){
      if(state[i] == NOT_VISITED) run(i);
    }

    int cnt = 0;
    for(int i=1; i<=N; i++){
      if(state[i] != CYCLE_IN) cnt++;
    }
    cout << cnt << '\n';
  }
}