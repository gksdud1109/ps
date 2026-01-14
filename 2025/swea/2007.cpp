#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	int T;
  cin >> T;

  for(int test_case = 1; test_case <= T; ++test_case) {
    string inputStr;
    cin >> inputStr;

    int len = inputStr.length();
    int pattLen = len;

    for(int i = 1; i <= len; i++) {
      string pattern = inputStr.substr(0, i);
      bool valid = true;
      for(int j = 0; j < len; j += i) {
        if (inputStr.substr(j, i) != pattern) {
          valid = false;
          break;
        }
      }
      if (valid) {
        pattLen = i;
        break;
      }
    }

    int ans = len / pattLen;
    cout << "#" << test_case << " " << ans << "\n";
  }
	return 0;
}