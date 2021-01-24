#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, tmp;
	cin >> n;

	priority_queue<int, vector<int>> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (i % 2 == 0)
			max_heap.push(tmp);
		else
			min_heap.push(tmp);

		if (!max_heap.empty() && !min_heap.empty())
		{
			if (max_heap.top() > min_heap.top())
			{
				int a = max_heap.top();
				int b = min_heap.top();

				max_heap.pop();
				min_heap.pop();

				max_heap.push(b);
				min_heap.push(a);


			}
		}

		cout << max_heap.top() << '\n';
	}
}