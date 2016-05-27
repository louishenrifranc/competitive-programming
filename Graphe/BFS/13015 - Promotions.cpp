#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
/*
class A {
protected: int var;
public:
	A() { var = -1; cout << "A par default" << endl; };
	A(int i) { var = i; cout << "A avec parametre" << endl; }
	A(const A& a) { var = a.var; cout << "A par copie de A = " << endl; };
	A& operator = (const A& a)
	{
		var = a.var; cout << "A affectation" << endl;
		return *this;
	};
	friend inline ostream& operator<<(ostream& os, const A& a)
	{
		os << "(var=" << a.var << ")" << endl; return os;
	}
};

class B : public A
{
protected: A a;
public:
	B() : A(1) { cout << "B par defuat" << endl; };
	B(int j) : A(j) { cout << "B avec parametre " << endl; };
	B(const A& a) : A(a) { cout << "B par copie " << endl; };
};

int main()
{
	A a1; X;
	A a2(3); X;
	A a3(a1); X;
	A a3bis = a1; X;
	a1 = a2; X;
	B b1; X;
	B b2(4);
	B b3 = a1; X;
	B b3bis(a1); X;
	B b4; X;
	B b5 = b2; X;
	b1 = b4; X;

	system("pause");
	return 1;
}
*/

class A {
public:
	void M2() { cout << "M2 de A" << endl; };
	virtual void M1() { cout << "M1 de A" << endl; };
	virtual void M3() { cout << "M3 de A" << endl; };
};

class B : public A {
public:
	void M1() { cout << "M1 de B" << endl; };
	virtual void M2() { cout << "M2 de B" << endl; };
	void M3() { cout << "M3 de B" << endl; };
};

class C : public B
{
public:
	void M1() { cout << "M1 de C" << endl; }; // Meme si B::M1 n'est pas virtual, va remonter jusque a pour faire la résolution dynamique !!!
	void M2() { cout << "M2 de C" << endl; };
	void M3() { cout << "M3 de C" << endl; }
};

class D {
protected: A va; A& ra; B& rb;
public: D(A v, A& r, B& s) : va(v), ra(r), rb(s) {};
		void M1() {
			cout << "D::M1 :" << endl; va.M1(); ra.M1(); rb.M1();
		}
		void M2() {
			cout << "D::M2 : " << endl; va.M2(); ra.M2(); rb.M2();
		}
		void M3() {
			cout << "D::M3 : " << endl; va.M3(); ra.M3(); rb.M3();
		}
};


int main()
{
	A a;
	B b;
	C c;
	D d1(a, b, c);
	D d2(b, b, b);
	D d3(b, b, c);
	D d4(c, b, c);
	cout << "d1 :" << endl; d1.M1(); d1.M2(); d1.M3();
	cout << "d2 :" << endl; d2.M1(); d2.M2(); d2.M3();
	cout << "d3 :" << endl; d3.M1(); d3.M2(); d3.M3();
	cout << "d4 :" << endl; d4.M1(); d4.M2(); d4.M3();
	system("pause");
	return 1;

}


/*
int main()
{
	cout << (1 << 0);
	cout << "Nombre de bouteilles : " << endl;;
	int i;
	cin >> i;
	int n = ceil(log(i) / log(2));
	cout << "Il y aura " << n << " testeurs";
	cout << ". Nombre de morts ? " << endl;
	int nbvictimes;
	cin >> nbvictimes;
	cout << " Lesquels (de 1 a " << n << endl;
	int bitset(0);
	for (int i(0); i < nbvictimes; i++)
	{
		int a; cin >> a;
		bitset |= (1 << (a - 1));
	}
	cout << "La bouteille empoisonnée est la numéro" << bitset << endl;
	system("pause");
}
*/

/*
int main()
{
	int A, B, C, D;
	while (scanf("%d %d %d %d", &A, &B, &C, &D) == 4)
	{
		vector<vector<int>> P(C, vector<int>());
		set<int> S;
		for (int i(0); i < C; i++)
			S.insert(i);
		for (int i(0); i < 8; i++)
		{
			int a, b;
			cin >> a >> b;
			P[a].push_back(b);
			S.erase(b);
		}

		vector<int> dist(C, INT32_MAX);
		vector<int> level(C, 0);
		queue<int> q; for_each(S.begin(), S.end(), [&q, &dist](const int& a) { q.push(a); dist[a] = 0; });
		level[0] = S.size();

		while (!q.empty())
		{
			int u = q.front(); q.pop();
			for_each(P[u].begin(), P[u].end(), [&u, &dist, &level, &q](const int& a)
			{
				if (dist[a] == INT32_MAX)
				{
					dist[a] = dist[u] + 1;
					level[dist[a]]++;
					q.push(a);
				}
				else {
					if (dist[u] + 1 > dist[a])
					{
						level[dist[a]]--; dist[a] = dist[u] + 1; level[dist[a]]++;
					}
				}
			});
		}
		int compteur(0); int i(0);
		while (i < C && compteur + level[i] <= A)
			compteur += level[i++];
		cout << compteur << endl;

		while (i < C && compteur + level[i] <= B)
			compteur += level[i++];
		cout << compteur << endl;

		if (compteur == B)
			cout << (C - compteur);
		else
			cout << (C - (compteur + level[i]));
		cout << endl;
	}
	return 1;
}*/