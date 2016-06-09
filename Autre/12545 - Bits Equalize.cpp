#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	std::cin >> N; 
	int N1(N);
DEBUT:
	N--;
	string a; string b;
	cin >> a >> b;
	int nbZ(0), nbX(0), nbU(0),nbW(0), res(0); 
	if (a.size() != b.size()) {
		res = -1;
		goto END;
	}
	for (int i(0);i<a.size();i++)
	{
		if (a[i] == '0' && b[i] == '1') nbZ++;
		if (a[i] == '?')			nbX++;
		if (a[i] == '?' && b[i] == '1') nbW++;
		if (a[i] == '1' && b[i] == '0') nbU++;
	}
	if (nbU > nbZ + nbW) {
		res = -1;
		goto END;
	}
	else
		res = (nbU > nbZ ? nbU + nbX : nbU + (nbZ - nbU) + nbX );
END:
	cout << "Case " << N1-N << ": " << res << endl;
	if (N != 0) goto DEBUT;
	return 0;

}