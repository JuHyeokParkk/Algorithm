#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> N(n);

	for (int i = 0; i < n; i++)
		cin >> N[i];

	int m;
	cin >> m;

	vector<int> M(m);

	for (int i = 0; i < m; i++)
		cin >> M[i];

	sort(N.begin(), N.end());

	for (int i = 0; i < m; i++)
	{
		if (binary_search(N.begin(), N.end(), M[i]))
			cout << "1\n";

		else
			cout << "0\n";
	}
}