#include <iostream>

using namespace std;

int dp[1000000] = { 1,2,3, };

int main()
{
	int n;
	cin >> n;

	for (int i = 3; i < n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;

	cout << dp[n-1];
}