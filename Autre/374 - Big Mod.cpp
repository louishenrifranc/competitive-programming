#include <cstdio>
using namespace std;
/**
Formule a implementer
    (x*y)mod m =( (x mod m) * (y mod m) ) mod m
**/
int main() {
	int b, p, m, ans;

	while (scanf("%d\n%d\n%d", &b, &p, &m) != EOF) {
		ans = 1;
		b %= m;

		while (p) {
			if (p & 1)
			ans = (ans * b) % m;
			b = (b * b) % m;
			p >>= 1;

		}
		printf("%d\n", ans);
	}

	return 0;
}
