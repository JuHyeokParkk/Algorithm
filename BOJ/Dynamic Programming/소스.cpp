#include <iostream>

using namespace std;

int dp[41] = { 0,1,1, };



int main()
{
	int Test_case, n;
	cin >> Test_case;

	for (int i = 0; i < Test_case; i++)
	{
		cin >> n;
		
		if (n == 0) printf("1 0\n");
		else if (n == 1) printf("0 1\n");
		else
		{
			int k = 3;
			while (k <= n)
			{
				dp[k] = dp[k - 2] + dp[k - 1];
				k++;
			}
			printf("%d %d\n", dp[n - 1], dp[n]);
		}
	}

	return 0;
}


