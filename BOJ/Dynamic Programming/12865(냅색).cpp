#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<vector<int>> arr(n + 1, vector<int>(2, 0));
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++)
	{
			cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j < arr[i][0]) dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
		}
	}

	cout << dp[n][k];
}