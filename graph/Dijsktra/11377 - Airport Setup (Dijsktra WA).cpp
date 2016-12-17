#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#include<string.h>
using namespace std;
#define INF 1000000000

typedef pair<int,double> ii;
double dist[2002];
int parent[2002];
int N,K,M,Q;
map<int,vector<pair<int,double> > > EdgeList;
priority_queue<ii,vector<ii>,greater<ii>  >pq;
bool estAeroport[2002];
int main()
{

    int cas,a,b,w(0);
    scanf("%d",&cas);
    while(cas--)
    {
        EdgeList.clear();
        scanf("%d %d %d",&N,&M,&K);
        memset(estAeroport,false,sizeof (estAeroport));
        for(int i(0); i<K; i++)
        {
            scanf("%d",&a);
            estAeroport[a-1]=true;
        }

        for(int i(0); i<M; i++)
        {
            scanf("%d %d",&a,&b);
            a--;
            b--;

                if( estAeroport[a] && estAeroport[b] )
                {
                    EdgeList[a].push_back( ii(b,0) );
                    EdgeList[b].push_back( ii(a,0) );

                }
                else
                {
                    EdgeList[a].push_back( ii(b,1) );
                    EdgeList[b].push_back( ii(a,1) );
                }

            }
            scanf("%d",&Q);
            printf("Case %d:\n",++w);
            for(int k(0); k<Q; k++)
            {

                scanf("%d %d",&a,&b);
                a--;
                b--;
                if(a==b)  printf("0\n");
                else
                {
                    for(int i(0); i<N; i++) dist[i]= INF;
                    dist[a]=0;
                    parent[a]=-9;
                    pq.push(ii(a,0)  );
                    while(!pq.empty())
                    {
                        ii u=pq.top();
                        pq.pop();
                        if( u.second == dist[ u.first ] )
                        {
                            for(int i(0); i<EdgeList[u.first].size() ; i++)
                            {

                                ii  pai = EdgeList[u.first][i];
                                int v =pai.first;
                                double poids=pai.second;

                                if( dist[v] > dist[u.first] + poids )
                                {   parent[v]=u.first;
                                    dist[v] = dist[u.first]+poids;
                                    pq.push(ii(v,dist[v]));
                                }
                            }
                        }
                    }
                    int res(0);
                    if(dist[b]== INF) printf("-1\n");
                    else{
                        while(parent[b] != -9){
                            if(!estAeroport[b]) res++;
                            b=parent[b];
                        }
                        if(!estAeroport[b]) res++;
                        printf("%d\n",res);
                    }


                }


            }
        putchar('\n');

        }
        return 0;

}
