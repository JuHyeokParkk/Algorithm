#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair <int, int> pi;
int main()
{
	int n, num;
	pi temp;
	priority_queue<pi, vector<pi>, greater<pi>> pq;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (!num && pq.empty())
			cout << "0\n";

		else if (num)
		{
			pq.push(make_pair(abs(num), num));
		}

		else
		{
			temp = pq.top();
			cout << temp.second << '\n';
			pq.pop();
		}
	}
}