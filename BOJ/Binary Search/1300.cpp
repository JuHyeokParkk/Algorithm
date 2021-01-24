#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int low = 1;
    int high = k;
    int result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int sum = 0;

        for (int i = 1; i <= n; i++)
            sum += min(mid / i, n);
         
        if (sum >= k)
        {
            result = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    cout << result;
}