#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int N;
	std::cin >> N; getchar();
	int N1(N);
DEBUT:
	N--;
	
	string a; double res(0);
	getline(cin, a);
	string::iterator it = a.begin();
	while (it != a.end())
	{
		double MM(0); char b = *it;
		if (b >= 'C' && b <= 'O')
			MM = (b == 'C' ? 12.01 : (b == 'H' ? 1.008 : (b == 'O' ? 16.00 : 14.01)));
		if (it + 1 == a.end()) { res += MM;  goto END; }
		if (*(++it) >= '0' && *it <= '9') {
			int U = (*it - '0')*(pow(10, ((it + 1 != a.end() && *(it + 1) >= '0' && *(it + 1) <= '9') ? 1 : 0)));
			U += ((it + 1 != a.end() && *(it + 1) >= '0' && *(it + 1) <= '9') ? (*(++it) - '0') : 0);
			MM *= U;
		}
			res += MM;
	}
END:
	printf("%.3f\n", res);
	if (N != 0) goto DEBUT;
	return 0;

}