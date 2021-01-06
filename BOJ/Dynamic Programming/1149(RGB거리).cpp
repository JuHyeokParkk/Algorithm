#include <iostream>
#include <algorithm>

using namespace std;

int RGB[1000][3];
int dp(int n);

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> RGB[i][j];
	}

	cout << dp(n);

	return 0;
}

int dp(int n)
{
	for (int i = 1; i < n; i++)
	{
		RGB[i][0] += min(RGB[i - 1][1], RGB[i - 1][2]);
		RGB[i][1] += min(RGB[i - 1][0], RGB[i - 1][2]);
		RGB[i][2] += min(RGB[i - 1][0], RGB[i - 1][1]);
	}

	return min(min(RGB[n - 1][0], RGB[n - 1][1]), RGB[n - 1][2]);
}