#include <bits/stdc++.h>
using namespace std;

int n;
string patt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> patt;

    string prefix = patt.substr(0, patt.find('*'));
    string suffix = patt.substr(patt.find('*')+1);

    for(int i=0; i<n; i++){
        string cur; cin >> cur;

        if (prefix.size() + suffix.size() > cur.size()) {
            cout << "NE\n";
        }
        else if(cur.substr(0, prefix.size()) == prefix && cur.substr(cur.size()-suffix.size()) == suffix){
            cout << "DA" << '\n';
        } else {
            cout << "NE" << '\n';
        }
    }
}