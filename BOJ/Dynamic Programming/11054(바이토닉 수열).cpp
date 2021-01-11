#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int up[1000];
int down[1000];                     // �� ��� ���� ���ʿ������� �ѹ�, �����ʿ������� �ѹ� Ž�� �� -1 ���� ����� ����

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