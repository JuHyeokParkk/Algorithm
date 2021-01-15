#include <iostream>

using namespace std;

int arr[128][128];
int white = 0;
int blue = 0;

void divide(int x, int y, int n)
{

	int tmp = 0;

	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (arr[i][j])
				tmp++;
		}
	}

	if (tmp == n * n)
		blue++;
		
	else if (tmp == 0)
		white++;
	
	else
	{
		divide(x, y, n / 2);
		divide(x + n / 2, y, n / 2);
		divide(x, y + n / 2, n / 2);
		divide(x + n / 2, y + n / 2, n / 2);
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
			cin >> arr[i][j];
	}

	divide(0,0,n);
	
	cout << white << '\n' << blue;
}