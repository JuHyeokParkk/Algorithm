#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, c;
	cin >> n >> c;

	vector<int> home(n);

	for (int i = 0; i < n; i++)
		cin >> home[i];

	sort(home.begin(), home.end());

	int min_dis = 1;
	int max_dis = home[n - 1] - home[0];
	int result = 0;

	
	while (min_dis <= max_dis)
	{
		int mid = (min_dis + max_dis) / 2;

		int cnt = 1;
		int cur_home = home[0];

		for (int i = 1; i < n; i++)
		{
			if (home[i] - cur_home >= mid)
			{
				cnt++;
				cur_home = home[i];
			}
		}

		if (cnt >= c)
		{
			result = max(result, mid);
			min_dis = mid + 1;

		}

		else
			max_dis = mid - 1;
	}

	cout << result << '\n';

}