#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	queue<int> card;

	cin >> n;

	for (int i = 1; i <= n; i++)
		card.push(i);

	while (card.size() != 1)
	{
		card.pop();
		card.push(card.front());
		card.pop();
		
	}

	cout << card.front();
}