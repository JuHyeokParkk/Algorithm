#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;           

int main()
{
	string s1, s2;

	cin >> s1 >> s2;

	vector <vector<int>> arr(s1.size() + 1, vector<int>(s2.size()+1));

	for (unsigned int i = 1; i <= s1.size(); i++)
	{
		
		for (unsigned int j = 1; j <= s2.size(); j++)
		{
			arr[i][j] =  + max({ arr[i - 1][j - 1] + (s1[i - 1] == s2[j - 1]), arr[i - 1][j], arr[i][j - 1] });

			                   // 대각선 왼쪽 위에서 + 1 해야함
		}
	}

	cout << arr[s1.size()][s2.size()];
	
}