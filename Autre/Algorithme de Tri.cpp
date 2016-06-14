#include <stdio.h>
#include <cmath>

int main()
{
	long long a, b;
	while (scanf("%d %d", &a, &b) == 2)
		printf("%d\n", exp(ln(b) / a));
	return 1;
}