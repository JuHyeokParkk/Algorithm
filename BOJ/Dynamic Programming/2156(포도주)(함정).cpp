#include <iostream>
#include <algorithm>

using namespace std;

int arr[10003] = { 0, };
int dp[10003] = { 0, };

int main()
{
    int n;
    cin >> n;

    for (int i = 3; i < n + 3; i++)
        cin >> arr[i];

    for (int i = 3; i < n + 3; i++)
    {
        dp[i] = arr[i] + max(dp[i - 2], dp[i - 3] + arr[i - 1]);
        dp[i] = max(dp[i - 1], dp[i]);
    }

    cout << dp[n + 2];

    return 0;
}