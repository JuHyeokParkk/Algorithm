#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, temp, cnt = 0;

	vector<int> v;
	v.push_back(INT_MIN);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (v.back() < temp)
		{
			v.push_back(temp);
			cnt++;
		}
		else
		{
			vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
			*low = temp;
		}
	}

	cout << cnt;

}