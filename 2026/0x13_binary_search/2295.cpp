#include <bits/stdc++.h>
using namespace std;

int N;
int a[1005];
vector<int> two; // 두 수를 골랐을 때의 합의 집합

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) cin >> a[i];
  sort(a, a+N);
  for(int i=0; i<N; i++){
    for(int j=i; j<N; j++)
      two.push_back(a[i]+a[j]);
  }
  sort(two.begin(), two.end());
  for(int i=N-1; i>0; i--){
    for(int j=0; j<i; j++){
      // a[a]+a[b]+a[c]=a[i] -> two[m] = a[i]-a[j]
      if(binary_search(two.begin(), two.end(), a[i]-a[j])){
        cout << a[i];
        return 0;
      }
    }
  }
}