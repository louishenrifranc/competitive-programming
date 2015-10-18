#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#define INF 1000000
/**
Comme nombre de noeud > 100, on utilise pas FLoyd Warshall
Double Dijsktra en inversant source et destination
Puis recherche de tous les segments de route qui appartiennent au chemin(x) le(s) plus court(s)

**/
using namespace std;
#define MAXN 32767
int p,t;
int dist1[10000+5],dist2[10000+5];
typedef pair<int,int> ii;

vector<pair<int,int>  > EdgeList[MAXN];
priority_queue<ii,vector<ii>,greater<ii>  >pq;
                                                                // Classic Dijkstra
void dijsktra(int initial,int fin,int t[]){

pq.push(ii(initial,0));
int v,w;
t[initial]=0;
while(!pq.empty()){
    ii u=pq.top();pq.pop();
    if(u.second == t[u.first]){
        for(int i(0);i<EdgeList[u.first].size();i++){
            ii paire=EdgeList[u.first][i];
            v=paire.first;
            w=paire.second;
            if(  t[v] > t[u.first] + w  ){
                t[v]=t[u.first]+w;
                pq.push(ii(v,t[v]));
            }
        }
    }
}

}

int main(){
int l,a,b,res;

while(scanf("%d %d",&p,&t)==2){
    res=0;
    for(int i(0);i<p;i++){
        EdgeList[i].clear();


    }

   for(int i(0);i<p;i++){
    dist1[i]=dist2[i]=INF;
   }

    for(int i(0);i<t;i++){
        scanf("%d %d %d",&a,&b,&l);
        EdgeList[a].push_back(ii(b,l));
        EdgeList[b].push_back(ii(a,l));
    }
    dijsktra(0,p-1,dist1);
    dijsktra(p-1,0,dist2);

    int longueur=dist1[p-1];                    // Recuperation de la longueur entre la source et la destination ( = dist2[0]

    for(int i(0);i<p;i++){
        for(int j(0);j<EdgeList[i].size();j++){
            int v=EdgeList[i][j].first; int w=EdgeList[i][j].second;
                                                // Si on est sur un segment de chemin le plus court
                                                // Ici il y a deux conditions,qui devrait representer l'aller et le retour par ce segment de chemin
                                                // Mais ici on cherche juste a decorer de fleurs des deux cotes du bas coté des chemins
            if(dist1[i]+w+dist2[v] == longueur || dist2[i] + w + dist1[v] == longueur) res+=w;
        }
    }
    printf("%d\n",res);

}
	return 0;
}
