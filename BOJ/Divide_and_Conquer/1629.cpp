#include <iostream>

using namespace std;

long long int square(int a, int b, int c)
{
	if (b == 1)
	{
		return a % c;
	}

	long long int tmp_1 = square(a, b / 2, c);
	long long int tmp_2 = (b % 2 == 1 ? tmp_1 * a : tmp_1) % c;
	return (tmp_1 * tmp_2) % c;
}
int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	printf("%lld\n", square(a, b, c));
}