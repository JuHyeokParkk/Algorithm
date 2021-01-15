#include <iostream>

using namespace std;

int paper[2187][2187];
int negative = 0, zero = 0, one = 0;

void divide(int x, int y, int n)
{
	int one_count = 0, minus_count = 0;

	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (paper[i][j] == 1)
				one_count++;

			else if (paper[i][j] == -1)
				minus_count++;
		}
	}

	if (one_count == n * n)
		one++;

	else if (minus_count == n * n)
		negative++;

	else if (one_count == 0 && minus_count == 0)
		zero++;

	else
	{
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				divide(x + (n / 3) * j, y + (n / 3) * i, n / 3);
			}
		}
	}

	return;
}
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	}

	divide(0, 0, n);

	cout << negative << '\n' << zero << '\n' << one;
}