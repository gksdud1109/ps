#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    string temp = s;

    reverse(temp.begin(), temp.end());
    if(temp == s) cout << "1\n";
    else cout << "0\n";
    
    return 0;
}