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
	string a1, b1;
	cin >> a1 >> b1;
	bitset<31> a(a1), b(b1),c,d;
	cout << a.to_string() << " " << b.to_string() << endl;
	while (b.any())
	{
		for (int i(0); i < 31; i++)
		{
			c[i] = (a[i] == b[i] ? 0 : 1);
			d[i] = (a[i] && b[i] ? 1 : 0);
		}

		cerr << " " << c.to_string() << " " << d.to_string() << endl;

		a = c; cout << a.to_string() << " ";
		
		if (c[30] == 1) {
			cout << "overflow"; break;
		}
		else
			b = d << 1;
		cout << b.to_string() << endl;
	}
END:
	if (N != 0) goto DEBUT;
	return 0;

}