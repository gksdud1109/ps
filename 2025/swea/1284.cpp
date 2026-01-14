#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int P, Q, R, S, W;
    int aFee=0, bFee=0;
    int ans=0;
    cin >> P >> Q >> R >> S >> W;

    aFee = P*W;
    bFee = Q;
    if(W>R)
      bFee += S*(W-R);
    int result = (aFee < bFee) ? aFee : bFee;
    cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;
}