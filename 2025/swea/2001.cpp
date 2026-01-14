#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int board[16][16]={0};
    int ans=0;
    int n,m;
    cin >> n >> m;
    for(int j=0; j<n; j++)
      for(int i=0; i<n; i++)
        cin >> board[i][j];

    for(int j=0; j<n; j++){
      for(int i=0; i<n; i++){
        int sum=0;
        for(int dy=0; dy<m; dy++){
          for(int dx=0; dx<m; dx++){
            if (i + dx < n && j + dy < n)
              sum += board[i+dx][j+dy];
          }
        }
        if(ans<=sum)
          ans = sum;
      }
    }
    cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}