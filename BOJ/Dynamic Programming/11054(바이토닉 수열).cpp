#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int up[1000];
int down[1000];                     // 이 방법 말고도 왼쪽에서부터 한번, 오른쪽에서부터 한번 탐색 해 -1 빼는 방법도 있음

int main()
{
	int n;
	int result = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		up[i] = 1;
		down[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				up[i] = max(up[i], up[j] + 1);
			}

			else if (arr[i] < arr[j])
			{
				down[i] = max(down[i], down[j] + 1);
				down[i] = max(down[i], up[j] + 1);
			}
			
		
		}

		result = max(result, max(up[i], down[i]));
	}

	
		cout << result;
}