#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
	return a[0] < b[0];
}

int main()
{
	int n;
	cin >> n;

	vector <vector<int>> arr(n);
	vector<int> dp(n);

	for (int i = 0; i < n; i++)
	{
		arr[i] = vector<int>(2);
		cin >> arr[i][0] >> arr[i][1];
	}

	sort(arr.begin(), arr.end(), cmp);

	int result = 1;

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i][1] > arr[j][1])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		result = max(result, dp[i]);
	}

	cout << n - result;
}