#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> dp(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	int result = arr[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(result, dp[i]);
	}

	cout << result;
}