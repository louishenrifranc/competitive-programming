#include <stdio.h>
#include <string.h>
#include <map>
#include<stdlib.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;
/**
Edmond Karp Algorithm Maximum Flow

Minimum Cut, couper un graphe en deux parties tels que la source et la destination ne puisse pas communiquer
Le graphe est non direct,avec poids, complet
Le poids represente le coup pour couper le lien --> d'ou l'algo de Minimum Cut

On realise l'algo de Edmond Karp en se basant sur l'idée que les liens a supprimer a moindre cout seront les liens qui qui auront leur flux maximum
possible = flux qui circule, ainsi si on a  flux possible de 35 sur 1 - 2 alors 1 - 2 est un lien si l'on fait passer 35 dessus
Une autre remarque est que ces liens que l'on cherche auront un parent qui est connu et un autre inconnu (puisque le flux est nul dessus on ne
                                                                                                           peut plus continuer a cette extremite
                                                                                                           (condition dans le BFS t[u][v] > 0
                                                                                                           )
  --------------------------------------------------------------------------------------------------------------------------------------------


On enregistre les parents des noeuds.


Lors du dernier parcours du BFS, on initialise les parents à -1,



**/
typedef pair<int,int> ii;

map<int,vector<int> > iii; // La liste d'adjacence pour le BFS (plus rapide que la matrice d'adjacence pour trouver les noeuds adjacents d'un noeud)
int t[51][51],u[51][51];    // La matrice d'adjacence pour sauvegarder les poids
int n;
vector<ii> resultats;
int parent[51];

int s=0,d=1; // La source est tjrs le noeud 1 et la destination le noeud 2

bool bfs()
{
    for(int i(0); i<n; i++) parent[i]=-2  ;
    queue <int> q;
    q.push(s);
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == d) return true;             // Si on a atteint le noeud d, alors on peut sortir
        for(int i(0); i<iii[u].size(); i++)
        {
            int v=iii[u][i];
            if (parent[v] == -2 && t[u][v] > 0 ) // SI le neoud n'a jamais été visité et que il reste du poids sur le lien
            {
                q.push(v);
                parent[v] = u;
            }
        }
    }
    // Si on a pas reussit a atteindre le noeud de destination,on retourne false
    return false;
}


int ford()
{
    int u,v;

    int max_flow = 0; // Cas ou l'on veut avoir le max flow, on additionne a cahque boucle avec le path_flow

    while(bfs())    // Tant qu'il existe un chemin pour aller de source a destination
    {
        int path_flow = 1000000;    //


        for (v=d; v!=s; v=parent[v])    // Recherche du min flow sur le chemin de la destination a la source
        {
            u = parent[v];
            path_flow = min(path_flow, t[u][v]);
        }

        // Modification
        // Ajout de path_flow a v-u et retrait a u-v (un peu bizarre pour les graphes indirects, mais bon ca marche
                                                      // A plus de sens pour les graphes directs
        for (v=d; v!=s; v=parent[v])
        {
            u = parent[v];
            t[u][v] -= path_flow;

            t[v][u] += path_flow;
        }

        // Add path flow to overall flow

    }

    // Return the overall flow
    return 0;
}

int main()
{
    int a,b,w,s,t1,c,cas(0),m;
    while(scanf("%d %d",&n,&m)== 2 && (n || m) )
    {
        iii.clear();
        resultats.clear();
        for(int i(0); i<51; i++) for(int j(0); j<51; j++) t[i][j]=0;
        for(int i(0); i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&w);
            // On doit faire comme ca pour Edmond Carp MAximum Flow
            t[a-1][b-1]=w;
            t[b-1][a-1]=w;

            iii[a-1].push_back(b-1);
            iii[b-1].push_back(a-1);

        }
        ford();
        for(int i(0); i<n; i++)
        {
            if( parent[i] != -2)    // Si sur un lien le noeud i a un parent (donc connecte a la source
                for(int j(0); j<iii[i].size(); j++)
                    if(parent[iii[i][j]] == -2) // Et que le noeud 2 n'a pas de parents
                                                // Alors il est forcement un noeud du min cut
                        printf("%d %d\n",i+1,iii[i][j]+1);
        }
        putchar('\n');
    }
    return 0;
}
