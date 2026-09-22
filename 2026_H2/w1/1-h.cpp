#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100005];
int dp[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int max = -1000000000;
    for(int i=0; i<k; i++){
        cin >> arr[i];
        if(i==0) dp[i] = arr[i];
        else dp[i] = arr[i]+dp[i-1];
    }

    for(int i=k; i<n; i++){
        cin >> arr[i];

        dp[i]= dp[i-1] + arr[i] - arr[i-k];
        if(max < dp[i]) max = dp[i];
    }

    cout << max;
}