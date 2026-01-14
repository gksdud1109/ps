#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[101], V[101];
int dp[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 1; i <= N; i++)
    cin >> W[i] >> V[i];

  for (int i = 1; i <= N; i++) {
    for (int j = K; j >= W[i]; j--) {
      dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
    }
  }

  cout << dp[K];
}