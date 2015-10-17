#include<stdio.h>
#include<string.h>
#include<sstream>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<map>
using namespace std;
map<int,vector<int> > t;
map<int,int> dist;
queue<int> q;
map<int,int> parents;

/**


Graphe pas forcement complet, indirect, sans poids

Simple BFS avec l'affichage des parents

Recupere une ligne pas facile a traiter
**/

int main()
{
    int n,m,x;
    char * pch;
    char buffer[50];

    while(scanf("%d",&x)==1)
    {
        getchar();
        t.clear();
        for(int i(0); i<x; i++)
        {   /**
            Recupere la ligne de la forme 1-2,3,5
            Tokenize la ligne
            **/
            int a(0),b(0);
            gets(buffer);

            pch=strtok(buffer,"-, ");
            a=atoi(pch);
            while( (pch = strtok(NULL,"-, ")) != NULL)
            {
                b=atoi(pch);

                t[a].push_back(b);

            }

        }
        int cas;
        scanf("%d",&cas);

        printf("-----\n");
        for(int i(0); i<cas; i++)
        {

            scanf("%d %d",&n,&m);
            int m1(m);

            dist.clear();
            while(!q.empty()) q.pop();
            parents.clear();
            dist[n]=0;
            q.push(n);


            /** Classic BFS with backtracking*/

            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int i(0); i<t[u].size(); i++)
                {
                    int l=t[u][i];
                    if(!dist.count(l))
                    {
                        dist[l]=dist[u]+1;
                        parents[l]=u;
                        q.push(l);
                    }

                }

            }
            int d;
            vector<int> resultat;
            /** Si les deux noeuds sont deja connectes*/
            if( n== parents[m]) printf("%d %d",n,m1);
            /** Sinon ajoute les noeuds de passage dans le vecteur */
            else
            {
                while( (d=parents[m] ) !=  n  && d )    // Tant que l'on a pas retrouve la source ou que un noeud n'a pas de parents
                {
                    resultat.push_back(d);
                    m=d;
                }

                if(resultat.size() )
                {
                    printf("%d ",n);
                    for(int i(0); i<resultat.size(); i++) printf("%d ",resultat[resultat.size()-i-1]);
                    printf("%d",m1);
                }
                else printf("connection impossible");
            }
            putchar('\n');

        }
    }
}


