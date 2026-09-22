#include <bits/stdc++.h>
using namespace std;

string s, rot;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, s);

    for(char &c : s){
        if(c >= 'A' && c <= 'Z'){
            c = (c - 'A' + 13) % 26 + 'A';
        }
        else if(c >= 'a' && c<= 'z'){
            c = (c - 'a' + 13) % 26 + 'a';
        }
    }

    cout << s;
    return 0;
}