#include <bits/stdc++.h>
using namespace std;

int small7[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    
    for(int i=1; i<=9; i++){
        cin >> small7[i];
        sum += small7[i];
    }

    sort(small7 + 1, small7 + 10);

    for(int i=1; i<=9; i++){
        for(int j=i+1; j<=9; j++){
            if (sum - small7[i] - small7[j] == 100){
                for(int k=1; k<=9; k++){
                    if(k==i || k==j) continue;
                    cout << small7[k] << '\n';
                }
                return 0;
            }
        }
    }
}