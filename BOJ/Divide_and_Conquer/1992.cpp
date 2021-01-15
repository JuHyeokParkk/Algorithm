#include <iostream>

using namespace std;

char movie[65][65];

void divide(int x, int y, int n)
{
	
	int tmp = 0;

	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (movie[i][j] == '1')
				tmp++;
		}
	}

	if (tmp == n * n)
		cout << "1";

	else if (tmp == 0)
		cout << "0";

	else
	{
		cout << "(";
		divide(x, y, n / 2);
		divide(x + n / 2, y, n / 2);
		divide(x, y + n / 2, n / 2);
		divide(x + n / 2, y + n / 2, n / 2);
		cout << ")";
	}

	return;

	
}
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> movie[i];

	divide(0, 0, n);
}