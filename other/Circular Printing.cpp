#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <array>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#define X cout << endl; cout << endl
using namespace std;
/*
	Print a circular incremental array
	0 19 18 17 16 15
	1 20 31 30 29 14
	2 21 32 35 28 13
	3 22 33 34 27 12
	4 23 24 25 26 11
	5 6 7 8 9 10
*/
int main()
{
	constexpr auto x = 6;
	array<array<int, x>, x> tableau;
	int a(0), b(0), e(x), d(-1), c(x), i(0), j(0), incr(0), sig(0);

	while (incr != x*x)
	{
		if (incr == 0) { sig = 1; e--; }
		if (i == d && j == b) { sig = 1; e--; }
		if (i == e && j == b) { sig = 2; c--; }
		if (i == e && j == c) { sig = 3; d++; }
		if (i == d && j == c) { sig = 4; b++; }
		switch (sig)
		{
		case 1: tableau[i++][j] = incr++; break;
		case 2: tableau[i][j++] = incr++; break;
		case 3: tableau[i--][j] = incr++; break;
		case 4: tableau[i][j--] = incr++; break;
		}
	}

	for (int i(0); i < x; i++)
	{
		for (int j(0); j < x; j++)
			cout << tableau[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 1;

}