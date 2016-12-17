#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<map>
using namespace std;
int n,m,gpe,scc;
map<int ,vector<int> > s;


/**
ALGORITHME BFS

Graphe : Indirect, pas forcement complet,sans poids, representant un reseau.
Probleme du dépassement de TTL. DOnné une source et un TTL determine le nombre de borne qui ne sont pas atteintes

Algorithme du SIngle Source SHortest Path
              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Utilisation d'une MAP<int,vector<int>> pour le graphe, d'une Queue pile et d'une map<int,int> distance pour le BFS

**/




int main()
{
    int cas(0);
    int a,b;
    while(scanf("%d",&n)==1 && n != 0)  // Lecture du nombre de liens
    {
        s.clear();
        for(int i(0); i<n ; i++)
        {
            scanf("%d %d",&a,&b);
            s[a].push_back(b);      //Car indirect
            s[b].push_back(a);

        }

        int ttl,source;
        map<int,int> dist;
        queue<int> q;
        while(scanf("%d %d",&source,&ttl) &&( source!=0 || ttl != 0)){  // Tant que on lit les parametres Source et TTL
                                                                        // Et que les deux ne sont pas égales a 0

                dist.clear();                               // Initialisation
                while(!q.empty()) q.pop();

                q.push(source);     // ON met la source dans la pile
                dist[source]=0;

                while(!q.empty())       // Tant que la pile n'est pas vide
                {
                    int u=q.front();
                    q.pop();            // On recupere l'element  au dessus

                    for(int i(0);i<s[u].size();i++ ){       // Pour tous les adjacents a u
                        int n=s[u][i];
                        if(!dist.count(n) ){        // dist.count() renvoit le nombre d'occurence de la clé n
                                                    // SI on a déja visté ce noeud alors dist.count(n) =1
                                                    // SInon =0
                            dist[n]=dist[u]+1;
                            q.push(n);              // Ajoute a a la pile
                        }
                    }

                }
                int res(0);

                for(map<int,int>::iterator it=dist.begin() ; it != dist.end() ;it++) if( it->second  > ttl) res++;  // Toutes les distances > ttl

                res+=s.size() - dist.size();    /**
                                                                        !!!!!!!!!!!!!!!!!!!
                                                Le graphe n'est pas complet, tous les noeuds que l'on n'a pas visite ne sont pas dans la Map distance
                                                , il sont par la meme occasion pas joignable, donc on les ajoute a res
                                                **/

                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cas,res,source,ttl);
            }


    }
    return 0;
}
