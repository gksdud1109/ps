#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    double sum = 0;
    for(int i=0; i<n; i++){
        sum += numbers[i];
    }
    double average = sum/n;

    for(int i=0; i<n; i++){
        cout << numbers[i] << ' ';
    }

    cout << '\n';

    cout << fixed << setprecision(2) << average << '\n';

    return 0;
}