#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string home[25];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int n, cnt;
vector<int> answer;
int visited[30][30] = { 0, };

void dfs(int i, int j)
{
	visited[i][j] = 1;
	cnt++;

	for (int k = 0; k < 4; k++)
	{
		int x = j + dx[k];
		int y = i + dy[k];

		if (0 <= x && x < n && 0 <= y && y < n)
		{
			if (home[y][x] == '1' && !visited[y][x]) dfs(y, x);
		}
	}
	
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> home[i];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (home[i][j] == '1' && !visited[i][j])
			{
				cnt = 0;
				dfs(i, j);
			    answer.push_back(cnt);	
				j++;
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';

	for (unsigned int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';

	return 0;
}