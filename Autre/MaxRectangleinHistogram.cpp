#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> hist;

int maxRectangeHistogram(int  i, int j)
{
	if (i == j)
		return hist.at(i);
	else if (i > j)
		return 0;

	auto k = min_element(hist.begin() + i, hist.begin() + j);
	int indice = k - hist.begin();
	int score = *k;
	return max(score*((j - i)),
		max(maxRectangeHistogram(i, indice - 1),
			maxRectangeHistogram(indice + 1, j)));
}

int main()
{
	int N, a;
	cin >> N;

	while (N--)
		cin >> a, hist.push_back(a);

	cout << maxRectangeHistogram(0, hist.size() - 1);
	system("pause");
}