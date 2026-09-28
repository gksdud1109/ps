#include <bits/stdc++.h>
using namespace std;

int T, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> n;
        unordered_map<string, int> cloths;

        for(int i=0; i<n; i++){
            string name, type;
            cin >> name >> type;
            cloths[type]++;
        }
        int ans = 1;

        for(auto a: cloths){
            ans *= (a.second+1);
        }
        cout << ans - 1 << '\n';
    }

    return 0;
}