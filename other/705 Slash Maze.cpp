#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

int dfs(const int& i)
{
	return 0;
}

vector<vector<int> > graph(10000, vector<int>());
bitset<10000> visited;
int main()
{
	int n, m,ntour(0);
	while (scanf("%d %d", &n, &m) == 2 && (n || m))
	{
		ntour++;
		getchar();
		for (int i(0); i < n; i++)
		{
			for (int j(0); j < m; j++)
			{
				char a;
				scanf("%c", &a);
				if (a == '\\')
					graph[i*(m + 1) + j].push_back((i + 1)*(m + 1) + (j + 1)),graph[(i + 1)*(m + 1) + (j + 1)].push_back(i*(m + 1) + j);

				if (a == '/') 
					graph[i*(m + 1) + (j + 1)].push_back((i + 1)*(m + 1) + j),graph[(i + 1)*(m + 1) + j].push_back(i*(m + 1) + (j + 1));
				
			}
		}
		visited.reset();
		int lmax(0), ltot(0),res;
		for (int i(0); i < n*(m + 1); i++)
		{
			if (!visited[i]) 
				res = dfs(i),
					ltot = max(res, ltot),
					lmax += res;
			
		}
		printf("Maze #%d:\n", ntour);
	}
	// system("pause");
	return 0;
}