#include <iostream>
#include <queue>

using namespace std;

struct paper {
	int index;
	int importance;
};                        // 또는 pair 사용

int main()
{
	int T, n, m;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n >> m;
		queue<paper> printer;
		priority_queue<int> important;

		for (int i = 0; i < n; i++)
		{
			paper tmp;
			tmp.index = i;
			cin >> tmp.importance;
			important.push(tmp.importance);
			printer.push(tmp);
		}

		int cnt = 1;

		while (1)
		{
			if (important.top() == printer.front().importance)
			{
				if (m == printer.front().index)
				{
					cout << cnt << '\n';
					break;
				}

				else
				{
					cnt++;
					printer.pop();
					important.pop();
				}
			}

			else
			{
				printer.push(printer.front());
				printer.pop();
			}
		}

		
	}
}