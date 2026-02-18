#include <bits/stdc++.h>
using namespace std;

int N;
int a[100005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=1; i<=N; i++)
    cin >> a[i];
  
  int currentSum = 0, maxSum = -1001;
  for(int i = 1; i <= N; i++) {
    currentSum = max(0, currentSum) + a[i];
    maxSum = max(maxSum, currentSum);
  }

  cout << maxSum;
}