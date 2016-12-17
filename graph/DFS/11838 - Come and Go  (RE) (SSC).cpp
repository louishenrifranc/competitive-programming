#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#define MAX 2005
using namespace std;
int L[MAX],V[MAX],P[MAX],G[MAX][MAX];
int n,m,gpe,scc;
vector<int> s;

/**
Algorithme pour la recherche de Strong Connected Component
Permet aussi de dire si le graphe est complet, c'est le cas ici de l'algorithme on a
un compteur scc qui indique des que l'on rencontre une racine d'un sous graphe complet

Si ce scc vaut 1 alors il n'y a qu'un seul sous graphe complet : le graphe en entier

**/

void dfs(int v){
    L[v]=V[v]=++gpe;
    s.push_back(v);
    P[v]=1;
    for(int i(0);i<n;i++){
        if(G[v][i]){
            if(!V[i]){
                dfs(i);
            }
            if(P[i]) L[v]=min(L[v],L[i]);
        }}
        if(L[v] == V[v]){
            scc++;
            int u;
            do{
                u=s.back();
                s.pop_back();
                P[u]=0;

            }while(v != u);

    }
}


int main(){
    int a,b,x;

    while( scanf("%d %d",&n,&m)==2 && n && m){
    memset(G,0,sizeof(G));
    memset(V,0,sizeof(G));
    memset(P,0,sizeof(G));
    memset(L,0,sizeof(G));
    s.clear();
        for(int i(0);i<m;i++){

            scanf("%d %d %d",&a,&b,&x);
            if( x == 1) G[a-1][b-1]=1;
            else G[a-1][b-1]=G[b-1][a-1]=1;
        }
        scc=gpe=0;
        for(int i(0);i<n;i++){
            if(!V[i])
                dfs(i);
        }
        printf("%d\n",(scc == 1));


    }
    return 0;
}
