#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int t[101];

    for(int i=0; i<3; i++){
        int inTime, outTime;
        cin >> inTime >> outTime;

        for(int j=inTime; j<=outTime; j++){
            t[j]++;
        }
    }

    int fee = 0;

    for(int k=0; k<101; k++){
        int cur = t[k];
        if(cur == 1) fee += a;
        else if(cur == 2) fee += b;
        else if(cur == 3) fee += c;

    }
    
    cout << fee << '\n';

    return 0;

}