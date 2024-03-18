//re
//다음 번 째 집과 색이 달라야 함
//2~ N-1 까지 집에서 i-1, i+1의 색이 달라야 함

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int color[3];
int dp[1001][3];

int main()
{
	cin >> N;
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> color[0] >> color[1] >> color[2];
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[2];
	}

	cout << min(dp[N][0], min(dp[N][1], dp[N][2]));



	return 0;
}

