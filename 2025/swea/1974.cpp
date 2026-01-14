#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    bool rowChk = true, colChk = true, recChk = true;
    bool vis[10] = {0};
    int board[10][10] = {0};

    for (int i = 1; i <= 9; i++)
      for (int j = 1; j <= 9; j++)
        cin >> board[i][j];

    // 행 확인
    for (int i = 1; i <= 9; i++) {
      fill(vis, vis + 10, 0);
      for (int j = 1; j <= 9; j++) vis[board[i][j]] = true;
      for (int j = 1; j <= 9; j++) if (!vis[j]) rowChk = false;
    }

    // 열 확인
    for (int j = 1; j <= 9; j++) {
      fill(vis, vis + 10, 0);
      for (int i = 1; i <= 9; i++) vis[board[i][j]] = true;
      for (int i = 1; i <= 9; i++) if (!vis[i]) colChk = false;
    }

    // 3x3 네모 확인
    for (int r = 1; r <= 7; r += 3) {
      for (int c = 1; c <= 7; c += 3) {
        fill(vis, vis + 10, 0);
        for (int i = 0; i < 3; i++)
          for (int j = 0; j < 3; j++)
            vis[board[r + i][c + j]] = true;
        for (int i = 1; i <= 9; i++) if (!vis[i]) recChk = false;
      }
    }

    int result = (rowChk && colChk && recChk) ? 1 : 0;
    cout << "#" << test_case << " " << result << '\n';
	}

	return 0;
}