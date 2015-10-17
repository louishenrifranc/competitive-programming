#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#define INF 1000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int dist[20001];
map<int,vector<ii> > EdgeList;
priority_queue<ii,vector<ii>,greater<ii>  >pq; // C'est la maniere d'utiliser une priority queue pour des valeurs minimales
void init(int N);

int main(){

int cas,n,m,S,D,a,b,w;
scanf("%d",&cas);
for(int k(0);k<cas;k++){
    scanf("%d %d %d %d",&n,&m,&S,&D); // Nombre de noeud, nombre de liens, source,destination
    EdgeList.clear();
    for(int i(0);i<m;i++){
        scanf("%d %d %d",&a,&b,&w);
        EdgeList[a].push_back(ii(b,w));
        EdgeList[b].push_back(ii(a,w));
    }
    for(int i(0);i<n;i++) dist[i]=INF;

    // dijsktra

    dist[S]=0; pq.push(ii(0,S));
    while(!pq.empty()){
        ii u=pq.top();
        pq.pop();
        if( u.first == dist[ u.second ] ){
            for(int i(0);i<EdgeList[u.second].size() ; i++){

                ii pai = EdgeList[u.second][i];
                int v =pai.first;
                int poids=pai.second;

                if( dist[v] > dist[u.second] + poids ){
                    dist[v] = dist[u.second]+poids;
                    pq.push(ii(dist[v],v));
                }
            }
        }
    }


    printf("Case #%d: ",k+1);
    if(dist[D]==INF) printf("unreachable\n");
    else printf("%d\n",dist[D]);



}



}
