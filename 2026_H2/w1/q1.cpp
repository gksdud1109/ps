#include <bits/stdc++.h>
using namespace std;

string dopa = "abcde";

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // q1 앞에서부터 3개의 문자열을 출력하라
    cout << dopa.substr(0, 3) << '\n';

    // q2 문자열을 거구로해서 출력하라
    reverse(dopa.begin(), dopa.end());
    cout << dopa << '\n';

    // q3 거꾸로된 해당 문자열 끝에 "umzunsik"이란 문자열을 추가하라.
    dopa += "umzunsik";
    cout << dopa << '\n';

    return 0;
}