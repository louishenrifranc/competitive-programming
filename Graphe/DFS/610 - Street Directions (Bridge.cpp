#include<stdio.h>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;
int G[MAX][MAX], V[MAX], L[MAX], n, m, gpe;
/**


        0--- 1 ---2
            | \
            4--5

            Les arcs sont dans les deux sens, le but est de garder un minimum d'arc

            Si c'est un bridge  V(voisin) < L(i) alors on le garde, sinon on le supprime et on met l'arc g(i)(j) a 0.
            Entre parentheses, les scores entre parentheses....
                Arbre recursif:
                Trop complique a representer
                0-1 appelle 1-0 (rien grace a la deuxieme condition)
                    puis appelle 1-2 (qui appelle rien car 2 n'a pas de voisins)
                    puis appelle 1-4
                            qui appelle 4-1 (rien grace a la deuxieme condition)
                            qui appelle 4-5
                                            qui appelle 5-4 (rien grace ala 2eme...)
                                            qui appelle 5-1 on a 5 qui a comme score (5,1) maintenant et on supprime le lien 5-1
                                    qui modifie 4   -    5 et le supprime
                                        score (4,1) et (5,1)
                    puis appelle 1-5
                        qui appelle 4-5 et le supprime(deja supprime)

                    Resultat
                    : suppression de 5-1 et 4-5


**/

void dfs(int u, int v) {
    V[v] = L[v] = ++gpe;
    for(int i = 1; i <= n; i++) {

        if(G[v][i]) {   // SI il existe un lien

            if(!V[i]){  // SI on l'a pas encore visité i
                dfs(v, i);
                L[v] = min(L[v], L[i]); // Pour l'algo de recherche des bridges
                if(L[i] <= V[v]) {
                    G[i][v] = 0;        // Supprime le lien car ce n'est pas un bridge
                }
            } else if(i != u) {         // Cas particulier voir "deuxieme condition dan l'exemple ci dessus.
                                        // L'idee est des qu'il tombe sur une boucle, un noeud deja visite alors il supprime la liasion (ca marche en tout cas)

                L[v] = min(L[v], V[i]);
                G[i][v] = 0;
            }
        }
    }
}

int main() {
    int tt = 0;
    while(scanf("%d %d",&n,&m)==2 && n && m) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        memset(L, 0, sizeof(L));
        gpe = 0;

        printf("%d\n\n",++tt);

        for(int i=0; i<m; i++) {
            int a, b; scanf("%d %d",&a,&b);
            G[a][b] = G[b][a] = 1;
        }

        for(int i=1; i<=n; i++) // Boucle pour verifier les noeuds pas connectes en principe pas utile car toutes les intersections sont connectes
            if (!V[i]){
                dfs(i, i);
            }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if (G[i][j])
                    printf("%d %d\n",i,j);

        printf("#\n");
    }
}
