#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int n;
    cin >> n;


    int arr[11][11] = {0};
    arr[1][1] = 1;
    for(int i=2; i<=n; i++){
      for(int j=1; j<=i; j++){
        if(j == 1)
          arr[i][j] = arr[i-1][j];
        else if(j == i)
          arr[i][j] = arr[i-1][j-1];
        else
          arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
      }
    }

    cout << '#' << test_case << '\n';
    for(int i=1; i<=n; i++){
      for(int j=1; j<=i; j++){
        cout << arr[i][j] << ' ';
      }
      cout << '\n';
    }
    
	}
	return 0;
}