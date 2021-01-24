#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	vector<int> arr1(n);

	for (int i = 0; i < n; i++)
		cin >> arr1[i];

	sort(arr1.begin(), arr1.end());

	cin >> m;
	
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		cout << upper_bound(arr1.begin(), arr1.end(), num) - lower_bound(arr1.begin(), arr1.end(), num) << " ";
	}
	
}