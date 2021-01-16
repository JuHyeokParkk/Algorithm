#include <iostream>
#define mod 1000000007

using namespace std;  // Ȯ�� ��Ŭ���� ȣ����, ���� ���������ε� Ǯ�� ����

int square(long long int a, int b)
{
	long long int result = 1;

	while (b)         // �Ǵ� ���
	{
		if (b % 2)
		{
			result *= a;
			result %= mod;
		}

		a *= a;
		a %= mod;
		b /= 2;
	}

	return result;
}

int main()
{
	int n, k;
	cin >> n >> k;

	long long int n_fac = 1, B = 1;

	for (int i = 2; i <= n; i++)
	{
		n_fac *= i;
		n_fac %= mod;
	}

	for (int i = 2; i <= k; i++)
	{
		B *= i;
		B %= mod;
	}

	for (int i = 2; i <= n - k; i++)
	{
		B *= i;
		B %= mod;
	}

	long long int B2 = square(B, mod - 2);
	long long int answer = n_fac * B2 % mod;

	cout << answer;
}