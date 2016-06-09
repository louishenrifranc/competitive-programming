#include <stdio.h>
#include <cmath>

int main()
{
	double a, b;
	while (scanf("%lf\n%lf", &a, &b) == 2)
		printf("%.0lf\n", exp(log(b) / a));
	return 1;
}