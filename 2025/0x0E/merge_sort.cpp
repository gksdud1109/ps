#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = {15,25,22,357,16,23,-53,12,46,3};
int tmp[1000001];

void merge(int st, int en){
  cout << "merge " << st << ", " << en << '\n';
  int mid = (st+en)/2;
  int lidx = st;
  int ridx = mid;
  for(int i = st; i < en; i++) {
    // 1) 오른쪽 절반이 이미 모두 다 땡겨갔을 때
    if (ridx == en) tmp[i] = arr[lidx++];
    // 2) 왼쪽 절반이 이미 모두 다 땡겨갔을 때
    else if (lidx == mid) tmp[i] = arr[ridx++];
    // 3) 양쪽에 남은 요소가 모두 있을 때, 두 값을 비교
    else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++]; // 왼쪽 값이 작거나 같으면 (안정 정렬을 위해 같을 땐 왼쪽 우선)
    else tmp[i] = arr[ridx++]; // 그렇지 않으면 오른쪽 값을 선택
}
  for(int i=st; i<en; i++) arr[i] = tmp[i];
  
  for(int i=st; i<en; i++) 
    cout << tmp[i] << ' ';
  cout << '\n';
}

void merge_sort(int st, int en){
  if(en == st+1) return;
  int mid = (st+en)/2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, en);
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  merge_sort(0, n);
  for(int i = 0; i < n; i++) cout << arr[i] << ' '; // -53 3 12 15 16 22 23 25 46 357
}
/* 지피티가 그려준 그림
merge_sort(0,10)
└───┬──────────────────────────────────────────────────────────────┐
    │                                                              │
    ▼                                                              ▼
merge_sort(0,5)                                                merge_sort(5,10)
[0,5)                                                          [5,10)
    ├───┬──────────────────────┐                                  ├───┬───────────────────────┐
    │   │                      │                                  │   │                       │
    ▼   ▼                      ▼                                  ▼   ▼                       ▼
  [0,2)  [2,5)              merge(0,5)                           [5,7)  [7,10)              merge(5,10)
   │      │                    ⇒ [15,16,22,25,357]                │      │                      ⇒ [-53,3,12,23,46]
   │      │
   │      ├───┬──────────────┐
   │      │   │              │
   │      ▼   ▼              ▼
   │    [2,3) [3,5)         merge(2,5)
   │     ⇒ [22]  ┌───┬─────┐ ⇒ [16,22,357]
   │            │     │
   │            ▼     ▼
   │          [3,4) [4,5) → 병합(3,5) ⇒ [16,357]
   │
   ├───┬────────────┐
   │   │            │
   ▼   ▼            ▼
 [0,1) [1,2)     merge(0,2)
  ⇒[15]  ⇒[25]    ⇒ [15,25]

── 최종 병합 ──
merge(0,10): merge([15,16,22,25,357], [-53,3,12,23,46])
  ⇒ [-53,3,12,15,16,22,23,25,46,357]
*/