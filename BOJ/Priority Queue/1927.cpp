#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (!temp && pq.empty())
			cout << "0\n";

		else if (!temp)
		{
			cout << pq.top() << '\n';
			pq.pop();
		}

		else
			pq.push(temp);
	}
}