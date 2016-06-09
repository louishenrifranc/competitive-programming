#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;



int main()
{
	int N;
	std::cin >> N; getchar();
	int N1(N);
DEBUT:
	N--;
	float L, D, V, H;
	cin >> L >> D >> H >> V; L /= 1000; D /= 1000; V /= 1000; H /= 1000;
	int t = sqrt(2 * H / 9.81); int res = V*t;
	if (res <= D - 0.5 || res >= D + L + 0.5)
		cout << "FLOOR";
	else if (res >= D + 0.5 && res <= D + L - 0.5)
		cout << "POOL";
	else cout << "EDGE";
	cout << endl;
END:
	if (N != 0) goto DEBUT;
	return 0;

}