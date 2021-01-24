#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
long long int line[10001];

bool max_line(int mid)
{
	long long int cnt = 0;

	for (int i = 0; i < k; i++)
	{
		cnt += line[i] / mid;
	}

	if (cnt >= n) return true;

	return false;
}

int main()
{
	
	long long int high = -1, result = -1, low = 1;
	 
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> line[i];
		high = max(high, line[i]);
	}

	

	while (low <= high)
	{
		long long int mid = (low + high) / 2;

		if (max_line(mid))
		{
			result = max(result, mid);
			low = mid + 1;
		}

		else
			high = mid - 1;
	}

	cout << result;

	

}