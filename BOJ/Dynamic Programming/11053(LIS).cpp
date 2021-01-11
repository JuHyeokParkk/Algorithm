#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;          //O(nlogn) 방법 검색

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> dp(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;
	
	int result = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		
		result = max(result, dp[i]);
	}

	cout << result;
}

