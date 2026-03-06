#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz=0;

void push(int x){
  heap[++sz] = x;
  int idx = sz;
  while(idx != 1){
    int cur = idx/2;
    if(heap[cur] >= heap[idx]) break;
    swap(heap[cur], heap[idx]);
    idx = cur;
  }
}

int top(){
  return heap[1];
}

void pop(){
  heap[1] = heap[sz--];
  int idx = 1;
  while(2*idx <= sz){
    int lc = 2*idx, rc = 2*idx + 1;
    int max_child = lc; // 이름도 max_child로 변경
    
    // 오른쪽 자식이 존재하고, 오른쪽 자식이 왼쪽 자식보다 크면 타겟 변경
    if(rc <= sz && heap[rc] > heap[lc])
      max_child = rc;
      
    // 내가 가장 큰 자식보다 크거나 같으면 정상(최대 힙)이므로 멈춤
    if(heap[idx] >= heap[max_child]) break; 
    swap(heap[idx], heap[max_child]);
    idx = max_child;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N; cin >> N;
  while(N--){
    int comm; cin >> comm;
    if(comm == 0){
      if(sz==0) cout << 0 << '\n';
      else {
        cout << top() << '\n';
        pop();
      }
    }
    else
      push(comm);
  }
}