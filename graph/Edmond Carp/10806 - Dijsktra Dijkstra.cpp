#include <stdio.h>
#include <string.h>
#include <map>
#include<stdlib.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;
/**
Edmond Karp Algorithm Maximum Edge DIsjoint Path + Min Cost ( Dijsktra pour Edmond Carp)
**/
typedef pair<int,int> ii;
typedef pair<int,long long> li;
long long matrice[101][101];
int t[101][101];
map<int,vector<pair<int,long long> > > EdgeList; // La liste d'adjacence pour le BFS (plus rapide que la matrice d'adjacence pour trouver les noeuds adjacents d'un noeud)
// La matrice d'adjacence pour sauvegarder les poids

int parent[250];

int s,d,n,m,data,linkcapacity; // La source est tjrs le noeud 1 et la destination le noeud 2
long long coux;

bool dijkstra()
{
    map<int,long long> dist;
    for(int i(0); i<n; i++)
    {
        parent[i]=-1;
        dist[i]=10000000000000000;
    }
    parent[0]=-2;
    dist[0]=0;
    priority_queue<li,vector<li>,greater<li> > pq;
    pq.push(li(0,0));

    while(!pq.empty())
    {
        li top = pq.top() ;
        pq.pop();
        long long dista = top.second;
        int u =top.first;
        if(dista == dist[u] )
            for(int i(0); i<EdgeList[u].size(); i++)
            {
                li v = EdgeList[u][i];
                if(t[u][v.first] > 0  && dist[u] + v.second < dist[v.first])
                {
                    dist[v.first]=dist[u]+v.second;
                    parent[v.first] = u;
                    pq.push(li(v.first,dist[v.first]));
                }
            }

    }
// for(int i(0);i<n;i++) printf("%d ",parent[i]+1);printf("\n");
    return parent[n-1]!=-1 ;
}

bool ford()
{
    int v(n-1),u;
    coux=0;

    while(dijkstra() && data  > 0)
    {
        v=n-1;
        while(( u =parent[v] )!= -2 )
        {
            t[u][v]-=min(linkcapacity,data);
            t[v][u]+=min(linkcapacity,data);
            matrice[v][u]=-matrice[v][u];
            coux+= matrice[u][v]*min(linkcapacity,data);
            v=u;
        }
        data-=linkcapacity;

    }
    return data <= 0;

}



int main()
{
    int a,b;
    long long w;
    while(scanf("%d %d",&n,&m)==2)
    {
        EdgeList.clear();
        for(int i(0); i<n; i++) for(int j(0); j<n; j++)
            {
                t[i][j]=0;
                matrice[i][j]=0;
            }

        for(int i(0); i<m; i++)
        {
            scanf("%d %d %lld",&a,&b,&w);
            a--;
            b--;

            EdgeList[a].push_back(li(b,w));
            EdgeList[b].push_back(li(a,w));

            t[a][b]=t[b][a]=1;

            matrice[a][b]=matrice[b][a]=w;
        }
        scanf("%d %d",&data,&linkcapacity);
        for(int i(0); i<n; i++) for(int j(0); j<n; j++) if(t[i][j]) t[i][j]=linkcapacity;
//   for(int i(0); i<n; i++)  printf("%d ",i+1);putchar('\n');
        bool resultat=ford();
        if(resultat) printf("%lld\n",coux);
        else printf("Impossible.\n");
    }

return 0;
}
