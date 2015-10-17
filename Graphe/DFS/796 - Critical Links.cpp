#include<stdio.h>
#include <cstring>
#include <algorithm>
#include<vector>
#define MAX 1001
using namespace std;
int G[MAX][MAX], V[MAX], L[MAX], n, m, gpe;
vector<pair<int,int> > vv;



void dfs(int u, int v)
{
    V[v] = L[v] = ++gpe;
    for(int i = 0; i < n; i++)
    {

        if(G[v][i])     // SI il existe un lien
        {

            if(!V[i])   // SI on l'a pas encore visité i
            {
                dfs(v, i);
                L[v] = min(L[v], L[i]); // Pour l'algo de recherche des bridges
                if(L[i] > V[v])
                {
                    vv.push_back(make_pair(v,i));
                };
            }
            else if(i != u)             // Cas particulier voir "deuxieme condition dan l'exemple ci dessus.
            {
                // L'idee est des qu'il tombe sur une boucle, un noeud deja visite alors il supprime la liasion (ca marche en tout cas)

                L[v] = min(L[v], V[i]);
            }
        }
    }
}

int main()
{

    while(scanf("%d",&n) == 1 )
    {

        if(n==0 || n==1)            // Cas particulier a gerer
        {
            printf("0 critical links\n\n");
        }
        else
        {
            memset(G,0,sizeof(G));
            memset(V,0,sizeof(V));
            memset(L,0,sizeof(L));

            for(int i(0); i<n; i++)
            {
                int a,b,nn;
                scanf("%d (%d)",&a,&nn);    // Lit le serveur a et le nombre de ses connexions nn

                for(int j(0); j<nn; j++)
                {
                    scanf("%d",&b);
                    G[a][b]=1;              // Met a 1 toutes ses connexions
                }

            }
            gpe=0;                          // Initialise le compteur pour dfs_low et
            vv.clear();                     // le vector resultat
            for(int i(0); i<n; i++)
                if(!V[i]) dfs(i,i); // Appelle dfs plusieurs fois pour le cas de graphe non complet

            int resultat(0);

            printf("%d critical links\n",vv.size());

            sort(vv.begin(),vv.end()); // tri pour affichage par ordre croissant des serveurs




            for(int i(0); i<vv.size(); i++)
            {
                pair<int,int> paire=vv[i];
                if(paire.first>  paire.second) swap(paire.first,paire.second);
                        // Pour l'affichage si on a 1-0 afficher 0 - 1
                printf("%d - %d\n",paire.first,paire.second);
            }
            putchar('\n');
        }
    }
}
