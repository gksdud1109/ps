#include <bits/stdc++.h>
using namespace std;

int n, seonbal;
int alpha[26];
bool possible;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string s;
    for(int i=0; i<n; i++){
        cin >> s;

        alpha[s[0]-'a']++;
    }

    for(int j=0; j<26; j++){
        if(alpha[j] >= 5){
            possible = true;
            cout << (char)('a'+j);
        } 
    }

    if(!possible) cout << "PREDAJA";

    return 0;
}