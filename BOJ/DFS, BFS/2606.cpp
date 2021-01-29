#include <iostream>

using namespace std;

typedef struct Computer {
	int n, m;
	int arr[101][101];
}computer;
int visited[101] = { 0,1, };

void init(Computer* c);
int dfs(Computer* c, int start)
{
	int sum = 1;

	for (int i = 1; i <= c->n; i++)
	{
		if (!visited[i] && c->arr[start][i])
		{
			visited[i] = 1;
			sum += dfs(c,i);
		}
	}

	return sum;
}
int main()
{
	Computer* c = new Computer;
	
	cin >> c->n >> c->m;
	init(c);

	for (int i = 0; i < c->m; i++)
	{
		int a, b;
		cin >> a >> b;

		c->arr[a][b] = 1;
		c->arr[b][a] = 1;
	}

	cout << dfs(c, 1) - 1;

	delete c;
}

void init(Computer* c)
{
	for (int i = 1; i <= c->n; i++)
	{
		for (int j = 1; j <= c->n; j++)
			c->arr[i][j] = 0;
	}
}