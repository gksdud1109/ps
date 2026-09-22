#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for(char c : s){
        arr[c-'a']++;
    }

    for(int i=0; i<26; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}