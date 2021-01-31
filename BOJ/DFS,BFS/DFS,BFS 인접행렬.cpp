#include <iostream>			// 인접행렬 이용
#include <queue>

using namespace std;

typedef struct Graph {
	int n, m;
	int v[1001][1001];
}GraphType;

int visited[1001] = { 0, };


void init(GraphType* g);
void DFS_matrix(GraphType* g, int num); 
void BFS_matrix(GraphType* g, int num);

int main()
{
	int first;
	GraphType* g = new GraphType;
	init(g);

	cin >> g->n >> g->m >> first;

	for (int i = 0; i < g->m; i++)
	{
		int start, end;
		cin >> start >> end;

		g-> v[start][end] = 1;
		g-> v[end][start] = 1;
	}

	DFS_matrix(g, first);
	cout << '\n';
	BFS_matrix(g, first);
	delete g;
}

void init(GraphType* g)
{
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 1001; j++)
			g->v[i][j] = 0;
	}

	g->n = g->m = 0;
}

void DFS_matrix(GraphType* g, int num)
{
	visited[num] = 1; // 정점에 방문했다고 체크
	cout << num << " ";

	for (int i = 1; i <= g->n; i++)
	{
		if (!visited[i] && g->v[num][i])  // i에 방문하지 않았고 i로 향하는 정점이 있으면
			DFS_matrix(g, i);
	}
}

void BFS_matrix(GraphType* g, int num)
{
	queue<int> q;

	q.push(num);
	visited[num] = 0;
	

	while (!q.empty())
	{
		int pop_element = q.front();
		
		for (int i = 1; i <= g->n; i++)
		{
			if (visited[i] && g->v[pop_element][i])
			{
				visited[i] = 0;
				q.push(i);
			}
		}

		cout << q.front() << " ";
		q.pop();
	}



}