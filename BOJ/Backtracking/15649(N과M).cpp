#include <iostream>

using namespace std;

int n, m;
int visited[8] = { 0, };
int arr[8];

void back(int size)
{
	if (size == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			arr[size] = i + 1;
			back(size + 1);
			visited[i] = 0;
		}
	}
}
int main()
{
	
	cin >> n >> m;

	back(0);

	return 0;

	
}