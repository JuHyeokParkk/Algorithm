#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int n, m;
	int cnt = 0;
	cin >> n >> m;

	deque<int> Deque;

	for (int i = 1; i <= n; i++)
		Deque.push_back(i);

	for (int i = 0; i < m; i++)
	{
		int find, index;
		
		cin >> find;

		for (int i = 0; i < n; i++)
		{
			if (Deque[i] == find)
			{
				index = i;
				break;
			}
		}

		if (index <= Deque.size() / 2)
		{
			while (1)
			{
				if (find == Deque.front())
				{
					Deque.pop_front();
					break;
				}

				Deque.push_back(Deque.front());
				Deque.pop_front();
				cnt++;
			}
		}

		else
		{
			while (1)
			{
				if (find == Deque.front())
				{
					Deque.pop_front();
					break;
				}

				Deque.push_front(Deque.back());
				Deque.pop_back();
				cnt++;
			}
		}
	}

	cout << cnt;
}