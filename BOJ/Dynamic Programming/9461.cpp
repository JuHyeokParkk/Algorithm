#include <iostream>

using namespace std;

long long int dp[101] = { 1,1,1 };

int main()
{
	int Test_case, n;
	cin >> Test_case;

	for (int i = 0; i < Test_case; i++)
	{
		cin >> n;

		if (n < 4) 
			cout << 1 << endl;

		else
		{
			for (int i = 3; i < n; i++)
				dp[i] = dp[i - 2] + dp[i - 3];

			cout << dp[n - 1] << endl;
		}


	}
}