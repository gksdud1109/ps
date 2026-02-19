#include <bits/stdc++.h>
using namespace std;

int N;
int a[1005];
int D[1005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++)
    cin >> a[i];

  fill(D, D+N, 1);
  for(int i=0; i<N; i++)
    for(int j=0; j<i; j++)
      if(a[j] < a[i]) D[i] = max(D[i], D[j] + 1);

  cout << *max_element(D, D+N);
}