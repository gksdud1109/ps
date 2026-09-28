#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, int> nameToNum;
string numToName[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        string name;
        cin >> name;
        numToName[i] = name;
        nameToNum[name] = i;
    }

    for(int i=0; i<m; i++){
        string query;
        cin >> query;

        if(isdigit(query[0])){
            int num = stoi(query);
            cout << numToName[num] << '\n';
        } else {
            cout << nameToNum[query] << '\n';
        }
    }

    return 0;
}