#include <iostream>
#include <algorithm>

using namespace std;

int dp[500][500] = { 0, };

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> dp[i][j];
	}

	int max_value = -1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dp[i][j] += dp[i - 1][j];

			else
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);

			max_value = max(max_value, dp[i][j]);
		}
			
	}


	cout << max_value << endl;

}