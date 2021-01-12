#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	queue<int> human;

	for (int i = 1; i <= n; i++)
		human.push(i);

	cout << "<";
	while (human.size())
	{
		for (int i = 0; i < k - 1; i++)
		{
			human.push(human.front());
			human.pop();
		}

		
		cout << human.front();

		if (human.size() == 1)
			cout << ">";

		else
			cout << ", ";

		human.pop();

	}

	return 0;
}