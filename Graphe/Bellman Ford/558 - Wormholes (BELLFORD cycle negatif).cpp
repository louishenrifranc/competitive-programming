#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;
/**
Classic Bellman Ford algorithm pour la detection de cycle negatif
Contrairement au autres algorithmes il est pas necessaire de partir d'un point initial precis et d'avancer suivant les voisins
On initialise un noeud a dist[noeud] = 0 et apres on fait tourner l'algorithme de Bellman Ford noeud -1  fois pour chaque lien

En principe au bout de  v-1 fois on a relaxé tous les noeuds, ainsi si il y a un changement alors cela veut dire qu'il ya  yn cycle négatif
**/

/** La structure permet a l'algo d'aller plus vite, on a pas besoin de creer un liste d'adjacence **/

struct edges
{
    int u;
    int v;
    int w;
} e [2000 + 10];

int main ()
{
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        int n, m;
        scanf ("%d %d", &n, &m);

        for ( int i = 0; i < m; i++ )
            scanf ("%d %d %d", &e [i].u, &e [i].v, &e [i].w);

        int d [1000 + 10];
        for ( int i = 0; i <= n; i++ ) d [i] = INT_MAX;

                d [0] = 0; // Initialisation aléatoire

        // Bellman Ford
        // Si il n'y a aucun changement durant une iteration, on peut arreter l'algo (je ne l'ai pas fai la )
        for ( int i = 0; i < n - 1; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                if ( d [e [j].u] + e [j].w < d [e [j].v] )
                    d [e [j].v] = d [e [j].u] + e [j].w;
            }
        }

        bool have_negative_cycle = false;

// Recherche du cycle

        for ( int j = 0; j < m; j++ ) {
            if ( d [e [j].u] + e [j].w < d [e [j].v] )
                have_negative_cycle = true;
        }

        if ( have_negative_cycle ) printf ("possible\n");
        else printf ("not possible\n");

    }
    return 0;
}

// @END_OF_SOURCE_CODE
