#include <iostream>

using namespace std;

int dp[101][10] = { {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, };

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j < 9; j++)
		{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	int sum = 0;
	for (int j = 0; j < 10; j++)
	{
		sum = (sum + dp[n - 1][j]) % 1000000000;
	}

	cout << sum << endl;
}